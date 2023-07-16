#include "EventHandler.hpp"

void EventHandler::registerEventHandler(const char* eventName, EventCallback eventCallback) {
	eventHandlers[eventName] = eventCallback;
}
void EventHandler::unregisterEventHandler(const char* eventName) {
	eventHandlers.erase(eventName);
}
void EventHandler::triggerEvent(const char* eventName) {
	auto it = eventHandlers.find(eventName);
	if (it != eventHandlers.find(eventName)) {
		it->second();
	}
}

std::map<std::string, EventHandler::EventCallback> EventHandler::eventHandlers;
