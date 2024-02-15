#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
    int data;
    Node* next;
};

Node* generateLinkedList(int numberOfNodes);
void adjustPointers(Node* head);
int getNodeDataValue(Node* start, int nodeIndex, int totalNodes);
void displayLinkedList(Node* start, int totalNodes);
bool updateNodeDataValue(Node* start, int nodeToUpdate, int updatedValue, int totalNodes);

#endif // LINKED_LIST_H
