#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

struct StudentGrade
{
  std::string name;
  char grade;
};

class GradeMap{
  private:
    std::vector<StudentGrade> m_map;

  public:
  char& operator[](std::string name);

};

//use the std::vector::emplace_back() or std::vector::push_back() function to add a StudentGrade for this new student. When you do this, std::vector will add a copy of your StudentGrade to itself (resizing if needed, invalidating all previously returned references). Finally, we need to return a reference to the grade for the student we just added to the std::vector. We can access the student we just added using the std::vector::back() function.
  char& GradeMap::operator[](std::string name){
    auto found{std::find_if(m_map.begin(), m_map.end(), [&name](const StudentGrade& student){return name==student.name;})};

    if (found==m_map.end()){
      m_map.push_back(StudentGrade{name, ' '});
      return m_map.back().grade;
    }

  return found->grade;
  }

int main()
{
	GradeMap grades{};

	grades["Joe"] = 'A';
	grades["Frank"] = 'B';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	return 0;
}
