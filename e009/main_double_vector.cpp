#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#include "double_vector.h"
#include "distance.h"

using namespace std;

int main() {
    vector<double_vector> my_double_vector;
    vector<my_distance> all_pairs_distances;

    ifstream in_file;
    in_file.open("vector_2d.txt");

    int id = 0;
    double from, to;
    while (in_file >> from >> to) {
        double_vector d_vector = double_vector(from, to, id++);
        my_double_vector.push_back(d_vector);
    }

    for (auto vect : my_double_vector) {
        cout << vect.x << " " << vect.y << " cos dist with itself: " << cosine_distance(vect, vect) << endl;
    }
    cout << endl;

    int size = my_double_vector.size();

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            my_distance my_distance1(i, j, cosine_distance(my_double_vector[i], my_double_vector[j]));
            all_pairs_distances.push_back(my_distance1);
        }
    }
    sort(all_pairs_distances.begin(),
         all_pairs_distances.end(),
         [](const my_distance & left, const my_distance & right) -> bool {
             return left.cos_distance < right.cos_distance;
         });

    for (auto dist : all_pairs_distances) {
        cout << dist.id_1 << " " << dist.id_2 << " cos dist = " << dist.cos_distance << endl;
    }
    cout << endl;

    in_file.close();

    return 0;
}