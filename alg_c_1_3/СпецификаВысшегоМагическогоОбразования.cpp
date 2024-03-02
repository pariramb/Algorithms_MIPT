#include <iostream>
#include <limits>

int main() {
  enum { kMaxMatrix = 202 };
  int64_t min_operations[kMaxMatrix - 1][kMaxMatrix - 1];  // показывает минимальное число операций для
                                                           // перемножение матриц от i до j включительно
  int n;
  std::cin >> n;
  int64_t all_values[kMaxMatrix];
  int64_t min;
  int j;
  for (int i = 1; i < n + 1; ++i) {
    std::cin >> all_values[i];
  }
  for (int i = n - 2; i > 0; --i) {
    for (int difference = 1; difference < n - i; ++difference) {
      min = std::numeric_limits<int64_t>::max();
      j = i + difference;
      for (int k = i; k < j; ++k) {
        if (min >
            min_operations[i][k] + min_operations[k + 1][j] + all_values[i] * all_values[k + 1] * all_values[j + 1]) {
          min = min_operations[i][k] + min_operations[k + 1][j] + all_values[i] * all_values[k + 1] * all_values[j + 1];
        }
      }
      min_operations[i][j] = min;
    }
  }
  std::cout << min_operations[1][n - 1];
  return 0;
}