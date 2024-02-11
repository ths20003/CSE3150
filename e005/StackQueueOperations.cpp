#include "StackQueueOperations.h"

// Function definitions for stack operations
void pushToStack(std::stack<Data>& stack, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    int value;
    while (file >> value) {
        Data newData;
        newData.value = value;
        stack.push(newData);
    }
    file.close();
}

void popFromStack(std::stack<Data>& stack) {
    int sum = 0;
    while (!stack.empty()) {
        sum += stack.top().value;
        stack.pop();
    }

    if (sum < 0) {
        throw std::runtime_error("Negative sum detected on stack!");
    }
}

// Function definitions for queue operations
void pushToQueue(std::queue<Data>& queue, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    int value;
    while (file >> value) {
        Data newData;
        newData.value = value;
        queue.push(newData);
    }
    file.close();
}

void popFromQueue(std::queue<Data>& queue) {
    int sum = 0;
    while (!queue.empty()) {
        sum += queue.front().value;
        queue.pop();
    }

    if (sum < 0) {
        throw std::runtime_error("Negative sum detected on queue!");
    }
}
