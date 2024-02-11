#ifndef STACKQUEUEOPERATIONS_H
#define STACKQUEUEOPERATIONS_H

#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <stdexcept> // Include for std::runtime_error

// Define your struct
struct Data {
    int value;
};

// Function declarations for stack operations
void pushToStack(std::stack<Data>& stack, const std::string& filename);
void popFromStack(std::stack<Data>& stack);

// Function declarations for queue operations
void pushToQueue(std::queue<Data>& queue, const std::string& filename);
void popFromQueue(std::queue<Data>& queue);

#endif // STACKQUEUEOPERATIONS_H
