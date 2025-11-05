#include <Vector3d.h>
#include <iostream>

// Print a Vector3d to stdout in the form: Vector(x, y, z)
void Vector3d::print(const Vector3d& v){
  std::cout << "Vector(" << v.m_x << ", " << v.m_y << ", " << v.m_z << ")\n";
}