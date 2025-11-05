# Friend classes and friend member functions — 15.9\

This example demonstrates:\
- declaring a friend member function so one class can access another's private data,\
- a Point3d class with a member that moves the point by a Vector3d,\
- a Vector3d class that grants friend access to Point3d::moveByVector.\

Files\
- Question_1.cpp — small demo program that constructs a Point3d and a Vector3d and moves the point by the vector.\
- Point3d.h / Point3d.cpp — point class and implementations.\
- Vector3d.h / Vector3d.cpp — vector class and implementations.\

Notes\
These implementations may not be perfect; I'm still learning and don't want to focus too much on perfect design or best practices right now.