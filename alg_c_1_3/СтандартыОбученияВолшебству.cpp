#include <iostream>

int main() {
  int n;
  std::cin >> n;
  // zero - "Отвратительно" последняя, one - "Тролль" последняя оценка
  auto count_comb_with_zero = new int64_t[n]{1};
  auto count_comb_with_one = new int64_t[n]{1};
  for (int i = 0; i < n - 1; i++) {
    count_comb_with_zero[i + 1] = count_comb_with_one[i] + count_comb_with_zero[i];
    count_comb_with_one[i + 1] = count_comb_with_zero[i];
  }
  std::cout << count_comb_with_one[n - 1] + count_comb_with_zero[n - 1];
  delete[] count_comb_with_one;
  delete[] count_comb_with_zero;
  return 0;
}