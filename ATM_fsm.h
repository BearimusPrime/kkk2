#pragma once
#include <functional>
#include <memory>
#include <map>


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
    private:
    StateTransitionFunc Transition;
    public:
    StateMachine(StateTransitionFunc statetrans): Transition(statetrans) {}
    virtual void Handler() =0;
    virtual ~StateMachine() {}
    protected:
    void stateTransition(State newState)
    {
        StateTransitionFunc(newState);
    }
};
}