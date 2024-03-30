#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "double_vector.h"
#include "distance.h"

TEST_CASE("Test double_vector struct") {
    double_vector vec1(1.0, 2.0, 0);
    double_vector vec2(vec1);

    CHECK(vec1.x == 1.0);
    CHECK(vec1.y == 2.0);
    CHECK(vec1.id == 0);

    CHECK(vec2.x == 1.0);
    CHECK(vec2.y == 2.0);
    CHECK(vec2.id == 0);
}

TEST_CASE("Test vector operations") {
    double_vector vec1(1.0, 2.0, 0);
    double_vector vec2(3.0, 4.0, 1);

    CHECK(square(2.0) == 4.0);
    CHECK(dot_product(vec1, vec2) == 11.0);
    CHECK(magnitude(vec1) == doctest::Approx(2.236).epsilon(0.01)); 
}

TEST_CASE("Test cosine_distance function") {
    double_vector vec1(1.0, 2.0, 0);
    double_vector vec2(3.0, 4.0, 1);
    CHECK(cosine_distance(vec1, vec2) == doctest::Approx(0.179853).epsilon(0.01));
}

