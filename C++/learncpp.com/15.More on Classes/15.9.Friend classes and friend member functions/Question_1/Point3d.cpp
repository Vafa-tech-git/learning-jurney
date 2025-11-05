#include <iostream>
#include <Point3d.h>
#include <Vector3d.h>

class Vector3d;

// Print a Point3d to stdout in the form: Point(x, y, z)
void Point3d::print(const Point3d& printvar){
  std::cout << "Point(" << printvar.m_x << ", " << printvar.m_y << ", " << printvar.m_z << ")\n";
}

// Move this point by the components of the provided vector.
// Point3d::moveByVector has friend access to Vector3d's private members.
void Point3d::moveByVector(const Vector3d& v){
m_x += v.m_x;
m_y += v.m_y;
m_z += v.m_z;
}