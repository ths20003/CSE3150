#include <algorithm>
#include <cmath>

#ifndef __reachability_H_
#define __reachability_H_

#include <vector>

struct Reachability_Matrix
{

  std::vector<std::vector<int>> matrix;

  Reachability_Matrix();
  Reachability_Matrix(int n);
  Reachability_Matrix(std::vector<std::vector<int>> matrix);
  Reachability_Matrix(const struct Reachability_Matrix &x);
  Reachability_Matrix operator*(struct Reachability_Matrix vctr2) const;
  void print();
};

Reachability_Matrix remove_nonzero_diagonal_entries(Reachability_Matrix x);
Reachability_Matrix divide_and_normalize(Reachability_Matrix x);
Reachability_Matrix find_edge(Reachability_Matrix x);
Reachability_Matrix reachability(Reachability_Matrix x);

#endif