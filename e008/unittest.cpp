#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "perfect_number.h" 

TEST_CASE("Testing isPerfect function") {
    // Testing known perfect numbers
    CHECK(isPerfect(6) == true);
    CHECK(isPerfect(28) == true);
    CHECK(isPerfect(496) == true);
    CHECK(isPerfect(8128) == true);
    
    // Testing known non-perfect numbers
    CHECK(isPerfect(12) == false);
    CHECK(isPerfect(14) == false);
    CHECK(isPerfect(24) == false);
    
    // Testing edge cases
    CHECK(isPerfect(1) == false); 
    CHECK(isPerfect(2) == false); 
    CHECK(isPerfect(3) == false); 
    CHECK(isPerfect(4) == false); 
    CHECK(isPerfect(5) == false); 
    CHECK(isPerfect(4960) == false); 
    
}
