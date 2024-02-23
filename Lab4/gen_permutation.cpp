#include <cstdlib>
#include "gen_permutation.h"
#include "prefix_sum.h"
#include "fisher_yates.h"

void compute_permutation_of_array(int arry[], int length) {
    std::vector<int> vec(arry, arry + length);
    fisherYatesShuffle(vec); 
}

int get_lowest_prefix_sum_value(int arry[], int length) {
    int sum = 0, lowest_sum = 0;

    for (int i = 0; i < length; i++) {
        sum += arry[i];
        if (sum < lowest_sum) {
            lowest_sum = sum;
        }
    }
    return lowest_sum;
}

int index_of_lowest_prefix_sum_element(int arry[], int length) {
    int lowest_prefix_sum = get_lowest_prefix_sum_value(arry, length);
    int sum = 0, index_of_first_lowest_ps = 0; 

    for (int i = 0; i < length; i++) {
        sum += arry[i];
        if (sum == lowest_prefix_sum) {
            index_of_first_lowest_ps = i;
            break;
        }
    }
    return index_of_first_lowest_ps;
}

std::vector<int> generateWellBalancedList(int n) {
    // Step 1: Initialize a list of 2n + 1 integers
    std::vector<int> symbols(2 * n + 1);

    // Step 2: Fill the first element with 1
    symbols[0] = 1;

    // Step 3: Fill the next n elements with 1 (opening parentheses)
    //         and the next n elements with -1 (closing parentheses)
    std::fill(symbols.begin() + 1, symbols.begin() + n, 1);
    std::fill(symbols.begin() + n, symbols.end() - 1, -1); // Exclude the last -1

    // Step 4: Ensure the last element is -1
    symbols.back() = -1;

    // Step 5: Compute prefix sum
    std::vector<int> prefixSumArray(symbols.size() + 1, 0);
    for (size_t i = 1; i < prefixSumArray.size(); ++i) {
        prefixSumArray[i] = prefixSumArray[i - 1] + symbols[i - 1];
    }
    prefixSumArray.pop_back();

    return prefixSumArray;
}







