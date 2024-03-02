#include <algorithm>
#include <iostream>

int main() {
  int have_rope[100];
  int no_rope[100];
  int coordinates[100];
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> coordinates[i];
  }
  std::sort(coordinates, coordinates + n);
  have_rope[0] = no_rope[0] = 0;
  have_rope[1] = no_rope[1] = coordinates[1] - coordinates[0];
  for (int i = 2; i < n - 1; ++i) {
    have_rope[i] = std::min(have_rope[i - 1], no_rope[i - 1]) + coordinates[i] - coordinates[i - 1];
    no_rope[i] = have_rope[i - 1];
  }
  std::cout << std::min(no_rope[n - 2], have_rope[n - 2]) + coordinates[n - 1] - coordinates[n - 2];
  return 0;
}