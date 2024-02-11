#include <iostream>
#include <stack>
#include <queue>
#include "StackQueueOperations.h"

int main() {
    // Test with stack
    std::stack<Data> myStack;
    try {
        pushToStack(myStack, "input.txt");
        popFromStack(myStack);
        std::cout << "Stack operation successful!" << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Test with queue
    std::queue<Data> myQueue;
    try {
        pushToQueue(myQueue, "input.txt");
        popFromQueue(myQueue);
        std::cout << "Queue operation successful!" << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
