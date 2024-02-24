#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <vector>
#include <string>

namespace student_ns {
    struct student {
        int id;
        std::string name;
        int final;
        int midterm;
        std::vector<int> hw_grades;
    };

    double computeTotalScore(const student& s);
    void print_student(const student& s);
}

#endif
