#include <iostream>

int main() {
  int n;
  std::cin >> n;
  auto all_comb = new int64_t[n + 1];
  all_comb[0] = 3;
  all_comb[1] = 8;
  for (int i = 1; i < n - 1; ++i) {
    all_comb[i + 1] = 2 * all_comb[i] + 2 * all_comb[i - 1];
  }
  std::cout << all_comb[n - 1];
  delete[] all_comb;
  return 0;
}