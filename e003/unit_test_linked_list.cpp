#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "linked_list.h"

TEST_CASE("linked_list testing") {
    SUBCASE("build_new_linked_list") {
        struct node* linked_list_zero_elts = build_new_linked_list(0);
        CHECK(linked_list_zero_elts == nullptr);

        struct node* linked_list_one_elt = build_new_linked_list(1);
        CHECK_EQ(get_linked_list_data_item_value(linked_list_one_elt, 1, 1), 1);

        struct node* linked_list_two_elts = build_new_linked_list(2);
        CHECK_EQ(get_linked_list_data_item_value(linked_list_two_elts, 1, 2), 1);
        CHECK_EQ(get_linked_list_data_item_value(linked_list_two_elts, 2, 2), 2);

        // Clean up the allocated memory
        delete_linked_list(linked_list_zero_elts);
        delete_linked_list(linked_list_one_elt);
        delete_linked_list(linked_list_two_elts);
    }

    SUBCASE("update_data_in_linked_list") {
        struct node* linked_list = build_new_linked_list(3);

        CHECK(update_data_in_linked_list(linked_list, 1, 10, 3));
        CHECK_EQ(get_linked_list_data_item_value(linked_list, 1, 3), 10);

        CHECK(update_data_in_linked_list(linked_list, 2, 20, 3));
        CHECK_EQ(get_linked_list_data_item_value(linked_list, 2, 3), 20);

        CHECK_FALSE(update_data_in_linked_list(linked_list, 4, 30, 3)); // Invalid node_to_update

        // Clean up the allocated memory
        delete_linked_list(linked_list);
    }

    SUBCASE("print_linked_list") {
        struct node* linked_list = build_new_linked_list(3);

        // Redirect cout to a stringstream for testing output
        std::stringstream output;
        std::streambuf* coutBuffer = std::cout.rdbuf();
        std::cout.rdbuf(output.rdbuf());

        print_linked_list(linked_list, 3);

        // Reset cout buffer
        std::cout.rdbuf(coutBuffer);

        CHECK(output.str().find("1\n2\n3") != std::string::npos);

        // Clean up the allocated memory
        delete_linked_list(linked_list);
    }
}
