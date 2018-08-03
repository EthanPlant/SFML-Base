#include "statemanager.hpp"

void StateManager::addState(stateRef newState, bool isReplacing)
{
    this->isAdding = true;
    this->isReplacing = isReplacing;
    this->newState = std::move(newState);
}

void StateManager::removeState()
{
    this->isRemoving = true;
}

void StateManager::processStateChanges()
{
     // Check if removing a state
     if (this->isRemoving && !this->states.empty())
     {
         // Remove state
         std::cout << "Removing top state" << std::endl;
         this->states.pop();

        if (!this->states.empty())
        {
            // Resume previous state
            std::cout << "Resuming state" << std::endl;
            this->states.top()->resume();
        }
        this->isRemoving = false;
     }

    // Check if adding a state
     if (this->isAdding)
     {
         if (!this->states.empty())
         {
             if (this->isReplacing)
             {
                 // Remove currently running state
                 std::cout << "Replacing state" << std::endl;
                 this->states.pop();
             }
             else
             {
                 // Pause currently running state
                 std::cout << "Pausing current state" << std::endl;
                 this->states.top()->pause();
             }
         }
         
         // Add the new state
         std::cout << "Adding new state" << std::endl;
         this->states.push(std::move(this->newState));
         this->states.top()->init();
         this->isAdding = false;
     }
}

stateRef& StateManager::getActiveState()
{
    return this->states.top();  
}