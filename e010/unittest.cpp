#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Point3d.h"
#include "Triangle3d.h"

TEST_CASE("Point3d class tests") {
    Point3d p1(1.0, 2.0, 3.0);
    Point3d p2(4.0, 5.0, 6.0);

    CHECK(p1.get_x() == 1.0);
    CHECK(p1.get_y() == 2.0);
    CHECK(p1.get_z() == 3.0);

    CHECK(p2.get_x() == 4.0);
    CHECK(p2.get_y() == 5.0);
    CHECK(p2.get_z() == 6.0);

    SUBCASE("Setter and getter tests") {
        p1.set_x(10.0);
        p1.set_y(20.0);
        p1.set_z(30.0);

        CHECK(p1.get_x() == 10.0);
        CHECK(p1.get_y() == 20.0);
        CHECK(p1.get_z() == 30.0);
    }
}

TEST_CASE("Triangle3d class tests") {
    Point3d p1(0.0, 0.0, 0.0);
    Point3d p2(1.0, 0.0, 0.0);
    Point3d p3(0.0, 1.0, 0.0);
    Triangle3d triangle(p1, p2, p3);

    CHECK(triangle.calculate_area() == doctest::Approx(0.5));

    SUBCASE("Setter and getter tests") {
        Point3d p4(0.0, 1.0, 1.0);
        triangle.set_p3(p4);

        CHECK(triangle.get_p3().get_x() == 0.0);
        CHECK(triangle.get_p3().get_y() == 1.0);
        CHECK(triangle.get_p3().get_z() == 1.0);
    }
}
