#ifndef _EXP_DIGRAPH_H
#define _EXP_DIGRAPH_H

#include <vector>
#include <iostream>

void expensiveDigraphExactPaths(std::vector<std::vector<int>>& DNeg1, std::vector<std::vector<int>>& DZero, std::vector<std::vector<int>>& DPos1);
std::vector<std::vector<int>> read_matrix(std::istream& in_stream);
std::ostream& operator<<(std::ostream& os, const std::vector<int>& my_vector);
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<int>>& my_matrix);
std::vector<int> read_ints(std::istream& in_stream);

#endif
