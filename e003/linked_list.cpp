#include <iostream>
#include "linked_list.h"

void delete_linked_list(struct node*& start) {
    while (start != nullptr) {
        struct node* temp = start;
        start = start->next;
        delete temp;
    }
}

struct node* build_new_linked_list(int total_new_elements) {
    if (total_new_elements <= 0) {
        return nullptr;
    } else {
        struct node* root = new node{1, nullptr};  // Start with data value 1
        struct node* linked_list = root;

        for (int i = 2; i <= total_new_elements; i++) {
            linked_list->next = new node{i, nullptr};
            linked_list = linked_list->next;
        }

        return root;
    }
}


int get_linked_list_data_item_value(struct node* start, int node_number, int total_elements) {
    if (node_number <= 0 || node_number > total_elements || start == nullptr) {
        return -1;
    } else {
        struct node* linked_list = start;

        for (int i = 1; i < node_number; i++) {
            if (linked_list == nullptr) {
                return -1; // Handle the case where the list is shorter than expected.
            }
            linked_list = linked_list->next;
        }

        if (linked_list == nullptr) {
            return -1; // Handle the case where the list is shorter than expected.
        }

        return linked_list->data;
    }
}

bool update_data_in_linked_list(struct node* start, int node_to_update, int update_val, int total_elements) {
    if (node_to_update <= 0 || node_to_update > total_elements || start == nullptr) {
        return false;
    } else {
        struct node* linked_list = start;

        for (int i = 1; i < node_to_update; i++) {
            if (linked_list == nullptr) {
                return false; // Handle the case where the list is shorter than expected.
            }
            linked_list = linked_list->next;
        }

        if (linked_list == nullptr) {
            return false; // Handle the case where the list is shorter than expected.
        }

        linked_list->data = update_val;
        return true;
    }
}

void print_linked_list(struct node* start, int total_elements) {
    struct node* linked_list = start;

    for (int i = 0; i < total_elements && linked_list != nullptr; i++) {
        std::cout << linked_list->data << std::endl;
        linked_list = linked_list->next;
    }
}