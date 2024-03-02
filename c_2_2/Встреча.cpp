#include <iostream>
#include <vector>
#include <algorithm>

void MakeVector(std::vector<int>& vector, const size_t size) {
  vector.resize(size);
  for (size_t i = 0; i < size; ++i) {
    std::cin >> vector[i];
  }
}

size_t CountSame(std::vector<int>& vector, int find) {
  size_t counter = 0;
  std::sort(vector.begin(), vector.end());
  auto ptr_same = std::lower_bound(vector.cbegin(), vector.cend(), find);
  while (true) {
    if ((ptr_same != vector.cend()) && (*ptr_same == find)) {
      ++counter;
      ptr_same = std::lower_bound(ptr_same + 1, vector.cend(), find);
    } else {
      break;
    }
  }
  return counter;
}

int main() {
  int count;
  std::vector<int> vector;
  std::cin >> count;
  MakeVector(vector, count);
  int find;
  std::cin >> find;
  std::cout << CountSame(vector, find);
  return 0;
}