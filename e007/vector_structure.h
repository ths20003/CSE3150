#ifndef __VECTOR_STRUCT__
#define __VECTOR_STRUCT__
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct int_vector {
 int id;
 int from;
 int to;
 int_vector(const int_vector & i_v) : id(i_v.id), from(i_v.from), to(i_v.to) {}; // copy constructor
 int_vector() : id(-1), from(0), to(0) {}; // basic constructor
};


vector<int_vector> output_function(const string file_name);

#endif