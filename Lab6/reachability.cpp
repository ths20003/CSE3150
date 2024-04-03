#include "reachability.h"
#include <iostream>

using namespace std;

Reachability_Matrix remove_nonzero_diagonal_entries(Reachability_Matrix x)
{
  int n = x.matrix.size();

  Reachability_Matrix ret(n);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (x.matrix[i][j] == 1 || x.matrix[i][j] == -1)
      {
        ret.matrix[i][j] = 0;
      }
      else
      {
        ret.matrix[i][j] = x.matrix[i][j];
      }
    }
  }

  return ret;
}

Reachability_Matrix divide_and_normalize(Reachability_Matrix x)
{
  int n = x.matrix.size();

  Reachability_Matrix ret(n);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      ret.matrix[i][j] = x.matrix[i][j];
      ret.matrix[i][j] /= 2;
    }
  }

  return ret;
}

Reachability_Matrix find_edge(Reachability_Matrix x)
{
  int n = x.matrix.size();

  Reachability_Matrix ret(n);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (x.matrix[i][j] == 0)
      {
        ret.matrix[i][j] = 1;
      }
    }
  }
  return ret;
}

Reachability_Matrix reachability(Reachability_Matrix x)
{
  int n = x.matrix.size();

  Reachability_Matrix ret(n);

  for (int l = 2; l <= (log2(n) + 1); l++)
  {
    Reachability_Matrix M = x * x;
    M = remove_nonzero_diagonal_entries(M);
    M = divide_and_normalize(M);
    Reachability_Matrix Z = find_edge(M);

    cout << l << ":" << endl;
    M.print();
    cout << "Z" << endl;
    Z.print();

    Reachability_Matrix mtrx = (Z * M) * Z;

    cout << "mtrx" << endl;
    mtrx.print();

    x = mtrx;
  }
  ret = x;

  return ret;
}

Reachability_Matrix::Reachability_Matrix(int n)
{
  for (int i = 0; i < n; i++)
  {
    vector<int> sub_matrix;
    for (int j = 0; j < n; j++)
    {
      sub_matrix.push_back(0);
    }
    matrix.push_back(sub_matrix);
  }
}

Reachability_Matrix::Reachability_Matrix(vector<vector<int>> vctr2)
{
  for (auto i = vctr2.begin(); i < vctr2.end(); i++)
  {
    vector<int> vctr = *i;
    if (vctr.size() != vctr2.size())
    {
      throw logic_error("Input is not valid");
    }
  }
  matrix = vctr2;
}

Reachability_Matrix::Reachability_Matrix(const Reachability_Matrix &vctr2) : matrix(vctr2.matrix) {}

Reachability_Matrix Reachability_Matrix::operator*(Reachability_Matrix vctr2) const
{
  int horizontal = matrix.size();
  int vertical = horizontal; // square matrix

  vector<vector<int>> matrixr = vctr2.matrix;

  vector<vector<int>> ret;

  for (int i = 0; i < horizontal; i++)
  {
    vector<int> vtrsb;
    for (int j = 0; j < vertical; j++)
    {
      int t = 0;
      for (int k = 0; k < vertical; k++)
      {
        t += matrix[i][k] * matrixr[k][j];
      }
      vtrsb.push_back(t);
    }
    ret.push_back(vtrsb);
  }

  Reachability_Matrix reslt(ret);

  return reslt;
}

void Reachability_Matrix::print()
{
  for (auto i = matrix.begin(); i < matrix.end(); i++)
  {
    vector<int> vctr = *i;
    cout << "[";
    for (auto j = vctr.begin(); j < vctr.end(); j++)
    {
      int v = *j;
      cout << v;
      if (j != vctr.end())
      {
        cout << ", ";
      }
    }
    cout << "]" << endl;
  }
}