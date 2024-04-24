#include "Point3d.h"

Point3d::Point3d() : x(0.0), y(0.0), z(0.0) {}

Point3d::Point3d(const Point3d &p3d) : x(p3d.x), y(p3d.y), z(p3d.z) {}

Point3d::Point3d(double x_val, double y_val, double z_val) : x(x_val), y(y_val), z(z_val) {}

Point3d::~Point3d() {}

std::ostream& operator<<(std::ostream &out, const Point3d &point) {
    out << "(" << point.x << ", " << point.y << ", " << point.z << ")";
    return out;
}
