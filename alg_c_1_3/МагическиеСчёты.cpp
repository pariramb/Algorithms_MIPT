#include <iostream>

int main() {
  enum { kMax = 1000001 };
  int64_t count_actions[kMax]{0};
  int n;
  int64_t min;
  std::cin >> n;
  for (int i = 2; i < n + 1; ++i) {
    min = count_actions[i - 1];
    if (!(i % 2)) {
      min = std::min(min, count_actions[i / 2]);
    }
    if (!(i % 3)) {
      min = std::min(min, count_actions[i / 3]);
    }
    count_actions[i] = min + 1;
  }
  std::cout << count_actions[n];
  return 0;
}