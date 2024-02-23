#include "fisher_yates.h"
#include <cstdlib>

bool isWellBalanced(const std::vector<int>& array) {
    int prefixSum = 0;
    for (int num : array) {
        prefixSum += num;
        if (prefixSum < 0) {
            return false; 
        }
    }
    return true;
}

void fisherYatesShuffle(std::vector<int>& array) {
    int n = array.size();
    for (int i = n - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        std::swap(array[i], array[j]);
    }
}
