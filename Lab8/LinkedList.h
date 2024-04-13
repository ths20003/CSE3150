#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <memory>

class LinkedList {
public:
    struct Node {
        int data;
        std::shared_ptr<Node> next;
        Node() {};
        Node(Node* node) : data{node->data}, next{node->next} {};
        Node(int data, std::shared_ptr<Node> ptr) : data{data}, next{ptr} {};
    };

    struct CopyNode {
        std::weak_ptr<Node> weak_node_ptr;
    };

    LinkedList();
    ~LinkedList();

    void build_node_list(int k);
    CopyNode* build_copyNodes_weak_ptrs();
    void delete_node_shared_ptr_list();
    void print_node_list_shared_ptrs();
    void print_node_array_weak_ptrs(CopyNode* copyNodes);
    int getNodeCount() const;

private:
    std::shared_ptr<Node> root;
    int nodeCount;
};

#endif // LINKEDLIST_H
