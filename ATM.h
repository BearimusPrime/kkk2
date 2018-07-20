#pragma once
#include "ATM_fsm.h"
#include <functional>
#include <memory>
#include <map>

using namespace xDDD;

class ATM
{
    public:
    ATM()
    {
        createStateMap();
        currState = allStateMap[Idle];
    }

    void handle()
    {
        currState->Handler();
    }

    private:
    std::map<State,std::shared_ptr<StateMachine>> allStateMap;
    std::shared_ptr<StateMachine> currState;
    void createStateMap()
    {
        StateTransitionFunc transit = [this](State state)
        {
            this->currState = allStateMap[State];
        };
        allStateMap[IDLE] = std::make_shared<Idle>(transit);
        allStateMap[VALIDATING] = std::make_shared<Validating>(transit);
        allStateMap[PROCESSING] = std::make_shared<Processing>(transit);
        
    }
}