#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "linked_list.h"

TEST_CASE("LinkedList Tests") {

    SUBCASE("Initialization and Self-Referencing Node") {
        // Create a linked list with two elements
        Node* listWithTwoElements = generateLinkedList(2);
        Node* current = listWithTwoElements;
        // Traverse the list until the node that points to itself is found
        while (current != current->next) {
            current = current->next;
        }
        // Verify that the node points to itself
        CHECK(current == current->next);
    }

    SUBCASE("Pointer Jumping Algorithm Check") {
        // Create a linked list with five elements
        Node* listWithFiveElements = generateLinkedList(5);
        Node* nodesArray[5];
        Node* startNode = listWithFiveElements;
        Node* currentNode = listWithFiveElements;
        Node* lastNode;

        // Store pointers to each node in an array
        for (int i = 0; i < 5; i++) {
            nodesArray[i] = currentNode;
            currentNode = currentNode->next;
        }

        lastNode = currentNode;

        // Check that the first three nodes do not point to the last node
        for (int i = 0; i < 3; i++) {
            CHECK(nodesArray[i]->next != lastNode);
        } 
        // Check that the fourth and fifth nodes point to the last node
        CHECK(nodesArray[3]->next == lastNode);
        CHECK(nodesArray[4]->next == lastNode);

        // Perform pointer jumping algorithm
        adjustPointers(listWithFiveElements);
        
        // Verify that all nodes point to the last node
        for (int i = 0; i < 5; i++) {
            CHECK(nodesArray[i]->next == lastNode);
        }
    }

    SUBCASE("Retrieve Data Value of a Node") {
        // Create a linked list with three elements
        Node* listWithThreeElements = generateLinkedList(3);
        
        // Test retrieving data value of each node
        CHECK(getNodeDataValue(listWithThreeElements, 1, 3) == 1);
        CHECK(getNodeDataValue(listWithThreeElements, 2, 3) == 2);
        CHECK(getNodeDataValue(listWithThreeElements, 3, 3) == 3);
        CHECK(getNodeDataValue(listWithThreeElements, 4, 3) == -1); // Out of bounds index
    }

    SUBCASE("Update Data Value of a Node") {
        // Create a linked list with four elements
        Node* listWithFourElements = generateLinkedList(4);
        
        // Update data value of a node
        CHECK(updateNodeDataValue(listWithFourElements, 2, 100, 4) == true);
        CHECK(getNodeDataValue(listWithFourElements, 2, 4) == 100);
        // Attempt to update data value of a node out of bounds
        CHECK(updateNodeDataValue(listWithFourElements, 5, 100, 4) == false);
    }

    SUBCASE("Print Linked List") {
        // Create a linked list with five elements
        Node* listWithFiveElements = generateLinkedList(5);
        // Redirect cout to a stringstream for capturing the output
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
        
        // Print the linked list
        displayLinkedList(listWithFiveElements, 5);
        
        // Restore cout
        std::cout.rdbuf(old);
        
        // Verify the printed output
        std::string output = buffer.str();
        CHECK(output == "1\n2\n3\n4\n5\n");
    }
}
