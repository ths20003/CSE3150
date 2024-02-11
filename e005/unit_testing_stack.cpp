#include <iostream>
#include <stack>
#include <queue>
#include "StackQueueOperations.h"

// Function to perform unit tests for stack operations
void testStackOperations() {
    std::stack<Data> myStack;

    // Test pushing elements onto the stack
    pushToStack(myStack, "input.txt");

    // Print elements of the stack after pushing
    std::cout << "Stack elements after pushing: ";
    while (!myStack.empty()) {
        std::cout << myStack.top().value << " ";
        myStack.pop();
    }
    std::cout << std::endl;

    // Test popping elements from the stack
    try {
        popFromStack(myStack);
        std::cout << "Stack operation successful!" << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

// Function to perform unit tests for queue operations
void testQueueOperations() {
    std::queue<Data> myQueue;

    // Test pushing elements onto the queue
    pushToQueue(myQueue, "input.txt");

    // Print elements of the queue after pushing
    std::cout << "Queue elements after pushing: ";
    while (!myQueue.empty()) {
        std::cout << myQueue.front().value << " ";
        myQueue.pop();
    }
    std::cout << std::endl;

    // Test popping elements from the queue
    try {
        popFromQueue(myQueue);
        std::cout << "Queue operation successful!" << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main() {
    // Run tests for stack operations
    std::cout << "Running stack operations test..." << std::endl;
    testStackOperations();

    // Run tests for queue operations
    std::cout << "Running queue operations test..." << std::endl;
    testQueueOperations();

    return 0;
}
