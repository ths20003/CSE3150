#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "reachability.h"
#include <iostream>

using namespace std;

TEST_CASE("Remove nonzero diagonal entries")
{
  Reachability_Matrix x(3);
  x.matrix[0][0] = 1;
  x.matrix[1][1] = -1;
  x.matrix[2][2] = 0;
  x.matrix[0][1] = -1;
  x.matrix[1][0] = 0;
  x.matrix[0][2] = 0;
  x.matrix[2][0] = 1;
  x.matrix[1][2] = 1;
  x.matrix[2][1] = 0;

  Reachability_Matrix ret = remove_nonzero_diagonal_entries(x);

  REQUIRE(ret.matrix[0][0] == 0);
  REQUIRE(ret.matrix[1][1] == 0);
  REQUIRE(ret.matrix[2][2] == 0);
  REQUIRE(ret.matrix[0][1] == 0);
  REQUIRE(ret.matrix[1][0] == 0);
  REQUIRE(ret.matrix[0][2] == 0);
  REQUIRE(ret.matrix[2][0] == 0);
  REQUIRE(ret.matrix[1][2] == 0);
  REQUIRE(ret.matrix[2][1] == 0);
}

TEST_CASE("Normalize and divide by two")
{
  Reachability_Matrix x(3);
  x.matrix[0][0] = 0;
  x.matrix[1][1] = 1;
  x.matrix[2][2] = 1;
  x.matrix[0][1] = 1;
  x.matrix[1][0] = 1;
  x.matrix[0][2] = 0;
  x.matrix[2][0] = 0;
  x.matrix[1][2] = 1;
  x.matrix[2][1] = 0;

  Reachability_Matrix ret = divide_and_normalize(x);

  REQUIRE(ret.matrix[0][0] == 0);
  REQUIRE(ret.matrix[1][1] == 0);
  REQUIRE(ret.matrix[2][2] == 0);
  REQUIRE(ret.matrix[0][1] == 0);
  REQUIRE(ret.matrix[0][2] == 0);
  REQUIRE(ret.matrix[2][0] == 0);
  REQUIRE(ret.matrix[2][1] == 0);
}

TEST_CASE("Get zero edges")
{
  Reachability_Matrix x(3);
  x.matrix[0][0] = 0;
  x.matrix[1][1] = 1;
  x.matrix[2][2] = 1;
  x.matrix[0][1] = 1;
  x.matrix[1][0] = 1;
  x.matrix[0][2] = 0;
  x.matrix[2][0] = 0;
  x.matrix[1][2] = 1;
  x.matrix[2][1] = 0;

  Reachability_Matrix ret = find_edge(x);

  REQUIRE(ret.matrix[0][0] == 1);
  REQUIRE(ret.matrix[1][1] == 0);
  REQUIRE(ret.matrix[2][2] == 0);
  REQUIRE(ret.matrix[0][1] == 0);
  REQUIRE(ret.matrix[1][0] == 0);
}