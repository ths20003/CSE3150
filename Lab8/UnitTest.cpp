#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "LinkedList.h"

TEST_CASE("Test LinkedList functionality") {
    LinkedList list;

    SUBCASE("Test building node list") {
        list.build_node_list(5);
        CHECK(list.getNodeCount() == 5);
    }

    SUBCASE("Test printing node list shared_ptrs") {
        list.build_node_list(3);
        std::ostringstream oss;
        std::streambuf* old_cout = std::cout.rdbuf(oss.rdbuf());
        list.print_node_list_shared_ptrs();
        std::cout.rdbuf(old_cout);
        CHECK(oss.str() == "3 2 1 \n");
    }

    SUBCASE("Test building and printing node array weak_ptrs") {
        list.build_node_list(3);
        LinkedList::CopyNode* copyNodes = list.build_copyNodes_weak_ptrs();
        std::ostringstream oss;
        std::streambuf* old_cout = std::cout.rdbuf(oss.rdbuf());
        list.print_node_array_weak_ptrs(copyNodes);
        std::cout.rdbuf(old_cout);
        CHECK(oss.str() == "3 2 1 \n");
        delete[] copyNodes;
    }

    SUBCASE("Test deleting node shared_ptr list") {
        list.build_node_list(3);
        list.delete_node_shared_ptr_list();
        CHECK(list.getNodeCount() == 0);
    }
}
