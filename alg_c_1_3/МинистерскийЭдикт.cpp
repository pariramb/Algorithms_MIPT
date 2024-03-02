#include <iostream>

int main() {
  int64_t prev[10]{0, 1, 1, 1, 1, 1, 1, 1, 0, 1};
  int64_t pos[10]{0, 1, 1, 1, 1, 1, 1, 1, 0, 1};
  int n;
  std::cin >> n;
  if (n == 1) {
    std::cout << 8 << "\n";
    return 0;
  }

  for (int i = 0; i < n - 1; ++i) {
    pos[0] = prev[4] + prev[6];
    pos[1] = prev[6] + prev[8];
    pos[2] = prev[7] + prev[9];
    pos[3] = prev[4] + prev[8];
    pos[4] = prev[3] + prev[0] + prev[9];
    pos[6] = prev[1] + prev[7] + prev[0];
    pos[7] = prev[2] + prev[6];
    pos[8] = prev[1] + prev[3];
    pos[9] = prev[4] + prev[2];
    for (int i = 0; i < 10; i++) {
      prev[i] = pos[i];
    }
  }
  int64_t result = 0;
  for (int i = 0; i < 10; ++i) {
    result += pos[i];
  }

  std::cout << result - 1 << "\n";
  return 0;
}