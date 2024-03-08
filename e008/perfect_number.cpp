#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "perfect_number.h"

bool isPerfect(int num) {
    std::vector<int> divisors(num / 2);
    std::iota(divisors.begin(), divisors.end(), 1)
    int sum = std::accumulate(divisors.begin(), divisors.end(), 0,
        [num](int acc, int divisor) {
            return acc + (num % divisor == 0 ? divisor : 0);
        });
    return sum == num;
}
