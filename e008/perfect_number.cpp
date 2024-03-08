#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "perfect_number.h"

bool isPerfect(int num) {
    // Create a vector containing numbers from 1 to num/2
    std::vector<int> divisors(num / 2);
    std::iota(divisors.begin(), divisors.end(), 1);

    // Use std::accumulate to sum the divisors
    int sum = std::accumulate(divisors.begin(), divisors.end(), 0,
        [num](int acc, int divisor) {
            return acc + (num % divisor == 0 ? divisor : 0);
        });

    // Check if the sum equals the number
    return sum == num;
}
