#pragma once
#include <iostream>

class Vector3d;

class Point3d
{
private:
double m_x{};
double m_y{};
double m_z{};

public:
Point3d(double x, double y, double z) : m_x{x}, m_y{y}, m_z{z}{
}

// Print a Point3d to stdout.
static void print(const Point3d& printvar);

// Move the point by a Vector3d. Declared here; friend access to Vector3d is granted in Vector3d.h.
void moveByVector(const Vector3d& v);
};