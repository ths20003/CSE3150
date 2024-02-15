#include <iostream>
#include "linked_list.h"

using namespace std;

struct Node * generateLinkedList(int numberOfNodes) {
    if (numberOfNodes == 0) {
        return nullptr;
    } else {
        struct Node * head = new Node;
        head->data = -1;
        struct Node * current = head;

        for (int i = 0; i < numberOfNodes; i++) {
            if (i < numberOfNodes - 1) {
                current->next = new Node;
                current->data = i + 1;
                current = current->next;
            } else {
                current->next = current; // Final node points to itself
                current->data = i + 1;
            }
        }
        return head;
    }
}

void adjustPointers(Node * head) {
    Node* current = head;
    Node* endNode;
    Node* nextNode;

    while (current->next != current) {
        current = current->next;
    }
    endNode = current;
    current = head;

    while (current->next != current) {
        nextNode = current->next;
        current->next = endNode;
        current = nextNode;
    }
}

int getNodeDataValue(struct Node * start, int nodeIndex, int totalNodes) {
    if (nodeIndex > totalNodes) {
        return -1;
    } else {
        struct Node * currentNode = start;
        for (int i = 0; i < nodeIndex - 1; i++) {
            currentNode = currentNode->next;
        }
        return currentNode->data;
    }
}

void displayLinkedList(struct Node * start, int totalNodes) {
    struct Node * currentNode = start;
    for (int i = 0; i < totalNodes; i++) {
        cout << currentNode->data << endl;
        currentNode = currentNode->next;
    }
}

bool updateNodeDataValue(Node* start, int nodeToUpdate, int updatedValue, int totalNodes) {
    // Traverse the linked list to find the node to update
    Node* currentNode = start;
    for (int i = 1; i < nodeToUpdate && currentNode; ++i) {
        currentNode = currentNode->next;
    }
    // If the node is found within the bounds of the linked list
    if (currentNode && nodeToUpdate <= totalNodes) {
        currentNode->data = updatedValue;
        return true; // Successfully updated the data value
    } else {
        return false; // Node not found or out of bounds
    }
}
