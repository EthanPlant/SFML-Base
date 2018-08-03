#pragma once

#include <memory>
#include <stack>
#include <iostream>

#include "state.hpp"

typedef std::unique_ptr<State> stateRef;

class StateManager
{
    public:
        StateManager() {}
        ~StateManager() {}

        void addState(stateRef newState, bool isReplacing);
        void removeState();
        void processStateChanges();

        stateRef& getActiveState();

    private:
        std::stack<stateRef> states;
        stateRef newState;

        bool isReplacing;
        bool isAdding;
        bool isRemoving;
};