#pragma once
#include "MessagePort.h"


void MessagePort::addMessage(const std::string& receiver, const Message& message)override
{
    handler[receiver] = message;
}

 std::vector<Message> MessagePort::collectMessages(const std::string& receiver)override
 {
     
 }