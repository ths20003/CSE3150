#include <iostream>
#include <fstream>
#include <vector>
#include "exp_digraph.h"

void processFile(const std::string& filename, std::vector<std::vector<int>>& matrix) {
    std::ifstream in_file(filename);
    if (!in_file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    matrix = read_matrix(in_file);
    in_file.close();
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> DNeg1, DZero, DPos1;

    processFile("G-1.txt", DNeg1);
    processFile("G0.txt", DZero);
    processFile("G1.txt", DPos1);

    std::cout << "Input matrices:" << std::endl;
    std::cout << "DNeg1:" << std::endl;
    printMatrix(DNeg1);
    std::cout << "DZero:" << std::endl;
    printMatrix(DZero);
    std::cout << "DPos1:" << std::endl;
    printMatrix(DPos1);

    expensiveDigraphExactPaths(DNeg1, DZero, DPos1);

    std::cout << "\nOutput matrices after computation:" << std::endl;
    std::cout << "DNeg1:" << std::endl;
    printMatrix(DNeg1);
    std::cout << "DZero:" << std::endl;
    printMatrix(DZero);
    std::cout << "DPos1:" << std::endl;
    printMatrix(DPos1);

    return 0;
}
