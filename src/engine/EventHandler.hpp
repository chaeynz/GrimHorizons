#pragma once

#include <functional>
#include <map>
#include <string>

class EventHandler
{
	using EventCallback = std::function<void()>;
	static void registerEventHandler(const char* eventName, EventCallback eventCallback);
	static void unregisterEventHandler(const char* eventName);
	static void triggerEvent(const char* eventName);

	static std::map<std::string, EventCallback> eventHandlers;
};