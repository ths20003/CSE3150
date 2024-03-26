#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <sstream>
#include <vector>
#include "exp_digraph.h"

TEST_CASE("ExpensiveDigraphExactPathsTest") {
    std::vector<std::vector<int>> DNeg1 = {{0, 0}, {0, 0}};
    std::vector<std::vector<int>> DZero = {{0, 0}, {0, 0}};
    std::vector<std::vector<int>> DPos1 = {{0, 0}, {0, 0}};
    expensiveDigraphExactPaths(DNeg1, DZero, DPos1);
    CHECK_EQ(DNeg1[0][0], 0);
    CHECK_EQ(DNeg1[0][1], 0);
}

TEST_CASE("read_ints function") {
    std::istringstream is("1 2 3 4 5");
    std::vector<int> result = read_ints(is);

    CHECK(result == std::vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("read_matrix function") {
    std::istringstream is("1 2 3\n4 5 6\n7 8 9");
    std::vector<std::vector<int>> result = read_matrix(is);

    CHECK(result == std::vector<std::vector<int>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
}

// Additional test cases for read_matrix function
TEST_CASE("read_matrix function - empty input") {
    std::istringstream is("");
    std::vector<std::vector<int>> result = read_matrix(is);

    CHECK(result.empty());
}

TEST_CASE("read_matrix function - single element") {
    std::istringstream is("1");
    std::vector<std::vector<int>> result = read_matrix(is);

    CHECK(result == std::vector<std::vector<int>>{{1}});
}

TEST_CASE("read_matrix function - irregular matrix") {
    std::istringstream is("1 2\n3 4 5\n6 7");
    std::vector<std::vector<int>> result = read_matrix(is);

    CHECK(result == std::vector<std::vector<int>>{{1, 2}, {3, 4, 5}, {6, 7}});
}

// Additional test cases for operator<< functions
TEST_CASE("operator<< function - vector<int>") {
    std::stringstream ss;
    std::vector<int> my_vector = {1, 2, 3, 4, 5};
    ss << my_vector;

    CHECK(ss.str() == "1 2 3 4 5");
}

TEST_CASE("operator<< function - vector<vector<int>>") {
    std::stringstream ss;
    std::vector<std::vector<int>> my_matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    ss << my_matrix;

    CHECK(ss.str() == "1 2 3\n4 5 6\n7 8 9");
}

TEST_CASE("Graphs") {
    std::vector<std::vector<int>> DNeg1 = {
        {-1, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2}
    };

    std::vector<std::vector<int>> DZero = {
        {0, 2, 2, 2, 2, 2},
        {2, 0, 2, 2, 2, 2},
        {2, 2, 0, 2, 2, 2},
        {2, 2, 2, 0, 2, 2},
        {2, 2, 2, 2, 0, 2},
        {2, 2, 2, 2, 2, 0}
    };

    std::vector<std::vector<int>> DPos1 = {
        {2, 1, 2, 2, 2, 2},
        {2, 2, 1, 2, 2, 2},
        {2, 2, 2, 1, 2, 2},
        {2, 2, 2, 2, 1, 2},
        {2, 2, 2, 2, 2, 1},
        {1, 2, 2, 2, 2, 2}
    };
}