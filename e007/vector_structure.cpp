#include "vector_structure.h"
using namespace std;
vector<int_vector> output_function(const string file_name) {
    vector<int_vector> vector1;
    ifstream infile(file_name);
    if(infile) {
        string s1;
        string first_num, second_num;
        int x = 0;
        while(getline(infile, s1)) {
            stringstream ss(s1);
            getline(ss, first_num, ' ');
            getline(ss, second_num, ' ');
            int first, second;
            first = stoi(first_num);
            second = stoi(second_num);
            int_vector v1;
            v1.id = x;
            v1.from = first;
            v1.to = second;
            vector1.push_back(v1);
            // cout << "id: " << v1.id << " from: " << v1.from << " to: " << v1.to << endl;
            x++;
        } 
    }
    reverse(vector1.begin(), vector1.end());
    for(int i = 0; i < vector1.size(); i++) {
        cout << vector1[i].id << ": " << vector1[i].from << " " << vector1[i].to << endl;
    }
    return vector1;
}
