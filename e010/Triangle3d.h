#ifndef TRIANGLE3D_H
#define TRIANGLE3D_H

#include "Point3d.h"

class Triangle3d {
private:
    Point3d p1;
    Point3d p2;
    Point3d p3;

public:
    Triangle3d();
    Triangle3d(const Point3d &p1, const Point3d &p2, const Point3d &p3);
    ~Triangle3d();

    Point3d get_p1() const { return p1; }
    Point3d get_p2() const { return p2; }
    Point3d get_p3() const { return p3; }

    void set_p1(const Point3d &p1_val) { p1 = p1_val; }
    void set_p2(const Point3d &p2_val) { p2 = p2_val; }
    void set_p3(const Point3d &p3_val) { p3 = p3_val; }

    double calculate_area() const;
};

#endif // TRIANGLE3D_H
