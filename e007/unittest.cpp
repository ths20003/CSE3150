#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "vector_structure.h"

using namespace std;

TEST_CASE("TEST CASE 1") {
    cout << "TESTCASE 1 WITH FILE:" << endl;
    string file_name = "test_input.txt";
    ofstream outfile(file_name);
    outfile << "5 7\n";
    outfile << "8 9\n";
    outfile.close();
    ifstream infile(file_name);
    string line;
    while(getline(infile, line)) {
        cout << line << endl;
    }
    cout << "FILE OUTPUT: " << endl;
    vector<int_vector> result = output_function(file_name);
    int_vector first_line;
    first_line.id = 1;
    first_line.from = 8;
    first_line.to = 9;
    int_vector second_line;
    second_line.id = 0;
    second_line.from = 5;
    second_line.to = 7;
    CHECK(result[0].id == first_line.id);
    CHECK(result[0].from == first_line.from);
    CHECK(result[0].to == first_line.to);

    CHECK(result[1].id == second_line.id);
    CHECK(result[1].from == second_line.from);
    CHECK(result[1].to == second_line.to);
}

TEST_CASE("TEST CASE 2") {
    string filenme = "test_input2.txt";
    ofstream outfile(filenme);
    outfile << "6 9\n";
    outfile << "8 3\n";
    outfile << "2 5\n";
    outfile << "34 32\n";
    outfile.close();
    string line2;
    ifstream infile(filenme);
    cout << "TESTCASE 2 WITH FILE:" << endl;
    while(getline(infile, line2)) {
        cout << line2 << endl;
    }
    cout << "FILE OUTPUT: " << endl;
    vector<int_vector> result2 = output_function(filenme);

    int_vector first, second, third, fourth;
    first.id = 3;
    second.id = 2;
    third.id = 1;
    fourth.id = 0;
    
    first.from = 34;
    first.to = 32;
    second.from = 2;
    second.to = 5;
    third.from = 8;
    third.to = 3;
    fourth.from = 6;
    fourth.to = 9;
    
    CHECK(result2[0].id == first.id);
    CHECK(result2[0].from == first.from);
    CHECK(result2[0].to == first.to);

    CHECK(result2[1].id == second.id);
    CHECK(result2[1].from == second.from);
    CHECK(result2[1].to == second.to);

    CHECK(result2[2].id == third.id);
    CHECK(result2[2].from == third.from);
    CHECK(result2[2].to == third.to);

    CHECK(result2[3].id == fourth.id);
    CHECK(result2[3].from == fourth.from);
    CHECK(result2[3].to == fourth.to);
}


TEST_CASE("TEST CASE 3") {
    cout << "TESTCASE 3 WITH FILE:" << endl;
    string file_n = "test_input3.txt";
    ofstream outfile(file_n);
    outfile << "-7 -2\n";
    outfile << "-1 -8\n";
    outfile << "76 85\n";
    outfile.close();
    ifstream infile(file_n);
    string s3;
    while(getline(infile, s3)) {
        cout << s3 << endl;
    }

    cout << "OUTPUT FILE: " << endl;
    vector<int_vector> result = output_function(file_n);

    int_vector first, second, third;

    first.id = 2;
    second.id = 1;
    third.id = 0;
    
    first.from = 76;
    first.to = 85;

    second.from = -1;
    second.to = -8;

    third.from = -7;
    third.to = -2;
    
    CHECK(result[0].id == first.id);
    CHECK(result[0].from == first.from);
    CHECK(result[0].to == first.to);

    CHECK(result[1].id == second.id);
    CHECK(result[1].from == second.from);
    CHECK(result[1].to == second.to);

    CHECK(result[2].id == third.id);
    CHECK(result[2].from == third.from);
    CHECK(result[2].to == third.to);    
}