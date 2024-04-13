#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : root(nullptr), nodeCount(0) {}

LinkedList::~LinkedList() {
    delete_node_shared_ptr_list();
}

void LinkedList::build_node_list(int k) {
    root = std::make_shared<Node>(Node(k, nullptr));
    auto current = root;
    for (int i = 1; i < k; ++i) {
        current->next = std::make_shared<Node>(Node(k - i, nullptr));
        current = current->next;
    }
    nodeCount = k;
}

LinkedList::CopyNode* LinkedList::build_copyNodes_weak_ptrs() {
    CopyNode* copyNodes = new CopyNode[nodeCount];
    auto current = root;
    for (int i = 0; i < nodeCount; ++i) {
        copyNodes[i].weak_node_ptr = current;
        current = current->next;
    }
    return copyNodes;
}

void LinkedList::delete_node_shared_ptr_list() {
    root.reset();
    nodeCount = 0;
}

void LinkedList::print_node_list_shared_ptrs() {
    auto current = root;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void LinkedList::print_node_array_weak_ptrs(CopyNode* copyNodes) {
    for (int i = 0; i < nodeCount; ++i) {
        auto sp = copyNodes[i].weak_node_ptr.lock();
        if (sp) {
            std::cout << sp->data << " ";
        } else {
            std::cout << "nullptr ";
        }
    }
    std::cout << std::endl;
}

int LinkedList::getNodeCount() const {
    return nodeCount;
}
