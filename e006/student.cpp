#include "student.h"
#include <iostream>

namespace student_ns {
    double computeTotalScore(const student& s) {
        double total_score = 0.3 * s.midterm + 0.3 * s.final;
        double hw_sum = 0;
        for (int grade : s.hw_grades) {
        hw_sum += grade;
   }
        total_score += 0.4 * (hw_sum / static_cast<double>(s.hw_grades.size()));

        return total_score;
    }

    void print_student(const student& s) {
        std::cout << "ID: " << s.id << std::endl;
        std::cout << "Name: " << s.name << std::endl;
        std::cout << "Total Class Score: " << computeTotalScore(s) << std::endl;
    }
}
