#include <iostream>

class Point3d{

private:
  int m_x;
  int m_y;
  int m_z;

public:
  void setvalues(int x, int y, int z){
    m_x = x;
    m_y = y;
    m_z = z;
  }
  
  void print(){
    std::cout << "<" << m_x << ", " << m_y << ", " << m_z << ">\n";
  }

  bool isequal(Point3d& comparationpoint) const {
    return (m_x == comparationpoint.m_x) && (m_y == comparationpoint.m_y) && (m_z == comparationpoint.m_z);
  }

};

int main(){

  Point3d point;
  point.setvalues(1, 2, 3);
  point.print();

  Point3d comparationpoint1{};
	comparationpoint1.setvalues(1, 2, 3);

	Point3d comparationpoint2{};
	comparationpoint2.setvalues(1, 2, 3);

	std::cout << "point 1 and point 2 are" << (comparationpoint1.isequal(comparationpoint2) ? "" : " not") << " equal\n";

	Point3d comparationpoint3{};
	comparationpoint3.setvalues(3, 4, 5);

	std::cout << "point 1 and point 3 are" << (comparationpoint1.isequal(comparationpoint3) ? "" : " not") << " equal\n";

  return 0;
}