#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "gen_permutation.h"

TEST_CASE("Generate Well-Balanced List Test") {
    SUBCASE("Test with various values of n") {
        for (int n = 1; n <= 5; ++n) {
            std::vector<int> wellBalancedList = generateWellBalancedList(n);

            std::cout << "Generated list for n = " << n << ": ";
            for (int val : wellBalancedList) {
                std::cout << val << " ";
            }
            std::cout << std::endl;

            CHECK(wellBalancedList.size() == 2 * n + 1);

            CHECK(wellBalancedList.front() == 0);
            CHECK(wellBalancedList.back() == 0);

            int numOpenParentheses = std::count(wellBalancedList.begin(), wellBalancedList.end(), 1);
            int numCloseParentheses = std::count(wellBalancedList.begin(), wellBalancedList.end(), -1);
            CHECK(numOpenParentheses == numCloseParentheses);

            int sum = 0;
            for (int i = 0; i < wellBalancedList.size(); ++i) {
                sum += wellBalancedList[i];
                CHECK(sum >= 0);
            }
        }
    }
}
