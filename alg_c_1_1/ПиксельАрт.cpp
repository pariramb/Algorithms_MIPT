#include <iostream>

#define MAX_COLORS 200000

int main() {
  uint64_t all_colors[MAX_COLORS]{};
  uint64_t n, m, k;
  std::cin >> n >> m >> k;
  uint64_t count_in_k = (m / k) * n;
  uint64_t count_in_n = (n / k) * (m % k);
  for (uint64_t i = 0; i < k; ++i) {
    all_colors[i] += count_in_k + count_in_n;
  }
  if (m % k + n % k > 0) {
    uint64_t count_diag = m % k + n % k - 1;
    for (uint64_t i = 0; i < count_diag; ++i)  //в оставшемся прямоугольнике
    {
      uint64_t min_side = std::min(m % k, n % k);
      uint64_t almost_squares_on_diam = std::min(i + 1, m % k + n % k - i - 1);
      uint64_t squares_on_diag = std::min(almost_squares_on_diam, min_side);
      all_colors[i % k] += squares_on_diag;
    }
  }
  for (uint64_t i = 0; i < k; ++i) {
    std::cout << all_colors[i] << ' ';
  }

  return 0;
}