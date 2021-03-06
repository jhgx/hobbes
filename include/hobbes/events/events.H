/*******************************
 * events : a runtime system for reactive programs
 ******************************/

#ifndef HOBBES_EVENTS_EVENTS_HPP_INCLUDED
#define HOBBES_EVENTS_EVENTS_HPP_INCLUDED

#include <functional>

namespace hobbes {

// add a read event handler for a file descriptor
typedef void (*eventhandler)(int fd, void* ud);

// return true to automatically repeat after an interval
typedef bool (*timerfunc)();

void addTimer(timerfunc f, int millisecInterval);

void registerEventHandler(int fd, const std::function<void(int)>& fn, bool vn = false /* only used on BSD */);
void registerEventHandler(int fd, eventhandler f, void* ud, bool vn = false /* only used on BSD */);
void unregisterEventHandler(int fd);

// run a single-step or indefinite event loop
bool stepEventLoop();
void runEventLoop();

// run the event loop for some number of microseconds
void runEventLoop(int microsecondDuration);

}

#endif

