#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "prefix_sum.h"

TEST_CASE("Calculate Prefix Sum on {1, -1, 1, -1}") {
    int testArray1[] = {1, -1, 1, -1};
    CHECK(prefix_sum(testArray1, sizeof(testArray1) / sizeof(testArray1[0])) == 0);
}

TEST_CASE("Calculate Prefix Sum on {-2, 3, -5, 6, 1}") {
    int testArray2[] = {-2, 3, -5, 6, 1};
    CHECK(prefix_sum(testArray2, sizeof(testArray2) / sizeof(testArray2[0])) == 3);
}

TEST_CASE("Non-negative Prefix Sum on {1, 2, 3, 4, 5}") {
    int testArray3[] = {1, 2, 3, 4, 5};
    CHECK(non_negative_prefix(testArray3, sizeof(testArray3) / sizeof(testArray3[0])) == true);
}

TEST_CASE("Non-negative Prefix Sum on {-1, -2, 3, -4, 5}") {
    int testArray4[] = {-1, -2, 3, -4, 5};
    CHECK(non_negative_prefix(testArray4, sizeof(testArray4) / sizeof(testArray4[0])) == false);
}

TEST_CASE("Non-positive Prefix Sum on {-1, 2, -3, 4, -5}") {
    int testArray5[] = {-1, 2, -3, 4, -5};
    CHECK(non_positive_prefix(testArray5, sizeof(testArray5) / sizeof(testArray5[0])) == true);
}

TEST_CASE("Non-positive Prefix Sum on {1, -2, 3, -4, 5}") {
    int testArray6[] = {1, -2, 3, -4, 5};
    CHECK(non_positive_prefix(testArray6, sizeof(testArray6) / sizeof(testArray6[0])) == false);
}
