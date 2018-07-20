#pragma once

#include <string>
#include <vector>
#include <map>
#include <messaging/Message.h>

class Messenger
{
public:
	virtual ~Messenger() = default;

	virtual void addMessage(const std::string& receiver, const Message& message) = 0;
	virtual std::vector<Message> collectMessages(const std::string& receiver) = 0;
	
	//onMessageReceived
};


class MessagePort : public Messenger
{
private:
std::map<std::string,std::string> handler;
public:
	virtual ~MessagePort () = default;
	virtual void addMessage(const std::string& receiver, const Message& message)override;
	virtual std::vector<Message> collectMessages(const std::string& receiver)override;
};
