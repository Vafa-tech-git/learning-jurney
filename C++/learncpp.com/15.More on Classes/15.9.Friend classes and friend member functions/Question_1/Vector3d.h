#pragma once
#include <iostream>
#include <Point3d.h>

class Point3d;

class Vector3d
{
private:
double m_x{};
double m_y{};
double m_z{};

public:
Vector3d(double x, double y, double z) : m_x{x}, m_y{y}, m_z{z}{
}

// Print a Vector3d to stdout.
static void print(const Vector3d& v);

// Allow Point3d::moveByVector to access private members of Vector3d.
friend void Point3d::moveByVector(const Vector3d& v);

// Accessors for read-only access to components.
double x() const { return m_x; }
double y() const { return m_y; }
double z() const { return m_z; }
};