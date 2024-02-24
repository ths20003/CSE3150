#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "student.h"

DOCTEST_TEST_CASE("Test computeTotalScore function") {
    {
        student_ns::student s;
        s.id = 1;
        s.name = "John";
        s.final = 90;
        s.midterm = 85;
        s.hw_grades = {80, 85, 90};

        double expected_total_score = 86.5; 
        double actual_total_score = student_ns::computeTotalScore(s);
        DOCTEST_CHECK(expected_total_score == doctest::Approx(actual_total_score));
    }

    {
        student_ns::student s;
        s.id = 2;
        s.name = "Alice";
        s.final = 80;
        s.midterm = 75;
        s.hw_grades = {70, 75, 80, 85};

        double expected_total_score = 77.5; 
        double actual_total_score = student_ns::computeTotalScore(s);
        DOCTEST_CHECK(expected_total_score == doctest::Approx(actual_total_score));
    }

}

DOCTEST_TEST_CASE("Test print_student function") {
    {
        student_ns::student s;
        s.id = 1;
        s.name = "John";
        s.final = 90;
        s.midterm = 85;
        s.hw_grades = {80, 85, 90};
        student_ns::print_student(s);
    }
    {
        student_ns::student alice;
        alice.id = 2;
        alice.name = "Alice";
        alice.final = 80;
        alice.midterm = 75;
        alice.hw_grades = {70, 75, 80, 85};
        student_ns::print_student(alice);
    }
}


