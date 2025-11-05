#include <Point3d.h>
#include <Vector3d.h>


int main()
{
Point3d p { 1.0, 2.0, 3.0 };
Vector3d v { 2.0, 2.0, -3.0 };

// Print original point, move it by v, then print updated point.
Point3d::print(p);
p.moveByVector(v);
Point3d::print(p);

return 0;
}