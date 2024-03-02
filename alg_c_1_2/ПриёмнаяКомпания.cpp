#include <algorithm>
#include <iostream>

#define MAX_NAME 40

struct Student {
  char surname[MAX_NAME];
  char name[MAX_NAME];
  int inf_points;
  int math_points;
  int rus_points;
  int sum_points;
};

bool Compare(Student* student1, Student* student2) {
  return student1->sum_points > student2->sum_points;
}

int main() {
  int n;
  std::cin >> n;
  auto students = new Student*[n];
  for (int i = 0; i < n; ++i) {
    students[i] = new Student;
    std::cin >> students[i]->surname;
    std::cin >> students[i]->name;
    std::cin >> students[i]->inf_points;
    std::cin >> students[i]->math_points;
    std::cin >> students[i]->rus_points;
    students[i]->sum_points = students[i]->math_points + students[i]->rus_points + students[i]->inf_points;
  }
  std::stable_sort(students, students + n, Compare);
  for (int i = 0; i < n; ++i) {
    std::cout << students[i]->surname << ' ' << students[i]->name << std::endl;
  }
  for (int i = 0; i < n; ++i) {
    delete students[i];
  }
  delete[] students;
  return 0;
}