#include "Triangle3d.h"
#include <cmath>

Triangle3d::Triangle3d() {}

Triangle3d::Triangle3d(const Point3d &p1_val, const Point3d &p2_val, const Point3d &p3_val)
    : p1(p1_val), p2(p2_val), p3(p3_val) {}

Triangle3d::~Triangle3d() {}

double Triangle3d::calculate_area() const {
    double d12 = sqrt(pow(p2.get_x() - p1.get_x(), 2) + pow(p2.get_y() - p1.get_y(), 2) + pow(p2.get_z() - p1.get_z(), 2));
    double d13 = sqrt(pow(p3.get_x() - p1.get_x(), 2) + pow(p3.get_y() - p1.get_y(), 2) + pow(p3.get_z() - p1.get_z(), 2));
    double d23 = sqrt(pow(p3.get_x() - p2.get_x(), 2) + pow(p3.get_y() - p2.get_y(), 2) + pow(p3.get_z() - p2.get_z(), 2));

    double s = (d12 + d13 + d23) / 2.0;
    return sqrt(s * (s - d12) * (s - d13) * (s - d23));
}
