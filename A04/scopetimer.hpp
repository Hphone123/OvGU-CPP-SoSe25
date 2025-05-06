#pragma once

#include <ctime> // Use the function std::clock() to measure time.
#include <iostream>

// The ScopeTimer measures the time between construction and
// destruction and writes it formatted with its name to the console.
class ScopeTimer{
public: 
    // Define the constructor and destructor in scopetimer.cpp
    ScopeTimer(const char* name);
    ~ScopeTimer();
private:    
    clock_t start_t;
    const char * name;
};