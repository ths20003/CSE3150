#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "perfect_number.h"

bool isPerfect(int num) {
    std::vector<int> vect_repeats(5, num);
    std::vector<int> divisors;
    for (int i = 1; i <= num / 2; ++i) {
        if (num % i == 0) {
            divisors.push_back(i);
        }
    }
    int sum = std::accumulate(divisors.begin(), divisors.end(), 0);
    return sum == num;
}
