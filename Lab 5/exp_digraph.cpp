#include "exp_digraph.h"
#include <sstream>
#include <iostream>

void expensiveDigraphExactPaths(std::vector<std::vector<int>>& DNeg1, std::vector<std::vector<int>>& DZero, std::vector<std::vector<int>>& DPos1) {
    int n = DZero.size();
    for (size_t l = 2; l <= 3 * n * n + 1; ++l) {
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                for (size_t k = 0; k < n; ++k) {
                    if (((DNeg1[i][k] + DPos1[k][j]) == 0) || ((DPos1[i][k] + DNeg1[k][j]) == 0)) {
                        DZero[i][j] = 0;
                    }
                    if (((DPos1[i][k] + DPos1[k][j]) == 1) || ((DZero[i][k] + DPos1[k][j]) == 1)) {
                        DPos1[i][j] = 1;
                    }
                    if (((DNeg1[i][k] + DZero[k][j]) == -1) || ((DZero[i][k] + DNeg1[k][j]) == -1)) {
                        DNeg1[i][j] = -1;
                    }
                }
            }
        }
    }
}

std::vector<int> read_ints(std::istream& in_stream) {
    std::vector<int> res;
    int i;
    while (in_stream >> i) {
        res.push_back(i);
    }
    return res;
}

std::vector<std::vector<int>> read_matrix(std::istream& in_stream) {
    std::vector<std::vector<int>> matrix;
    std::string line;
    while (std::getline(in_stream, line)) {
        std::istringstream is(line);
        matrix.push_back(read_ints(is));
    }
    return matrix;
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& my_vector) {
    for (size_t i = 0; i < my_vector.size(); ++i) {
        os << my_vector[i];
        if (i != my_vector.size() - 1) {
            os << " ";
        }
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<int>>& my_matrix) {
    for (size_t i = 0; i < my_matrix.size(); ++i) {
        os << my_matrix[i];
        if (i != my_matrix.size() - 1) {
            os << "\n";
        }
    }
    return os;
}
