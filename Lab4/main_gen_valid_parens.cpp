#include <iostream>
#include "gen_permutation.h"

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    std::vector<int> wellBalancedList = generateWellBalancedList(n);

    std::cout << "Generated well-balanced list of numbers:" << std::endl;
    for (int num : wellBalancedList) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
