#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "Message.h"
#include "Component.h"

class Dispatcher
{
public:
    virtual ~Dispatcher() = default;

    virtual void registerComponent(std::set<MessageId> types, std::shared_ptr<Component> component) = 0; //how about reference instead of shared_ptr?
    virtual void forwardMessage(const Message& message) = 0;
};

#endif //DISPATCHER_H
