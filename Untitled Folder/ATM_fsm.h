#pragma once
#include <functional>
#include <memory>
#include <map>
#include <iostream>


namespace xDDD
{
    enum State{
        IDLE = 1,
        VALIDATING = 2,
        PROCESSING = 3
    };

typedef std::function<void (State)> StateTransitionFunc;

class StateMachine
{
        StateTransitionFunc Transition;

    
    public:
    StateMachine(StateTransitionFunc statetrans): Transition(statetrans) {}
    virtual void Handler() =0;
    virtual ~StateMachine() {}
    protected:
    bool correctPin{true};
    void stateTransition(State newState)
    {
        Transition(newState);
    }
};

class Idle: public StateMachine
{
public:
    Idle(StateTransitionFunc stf): StateMachine(stf) {}
    virtual void Handler()override
    {
        std::cout<<"IDLE\n";
        //costam
        stateTransition(VALIDATING);
    }
};

class Validating: public StateMachine
{
    public:
    Validating(StateTransitionFunc stf): StateMachine(stf) {}
    virtual void Handler()override{
        //costam
         std::cout<<"VALIDATING!\n";

        if(!correctPin) stateTransition(IDLE);
        else stateTransition(PROCESSING);
    }
};
class Processing : public StateMachine
{
    public:
    Processing(StateTransitionFunc stf): StateMachine(stf) {}
    virtual void Handler()override{
        //costam
       std::cout<<"PROCESSING!\n";

        stateTransition(IDLE);
    }

};
}