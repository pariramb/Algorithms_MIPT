#include <iostream>

int main() {
  enum { kMaxLen = 101, kMod = 1000000 };
  int n;
  std::cin >> n;
  int64_t count_increase_seq[kMaxLen];
  int seq[kMaxLen];
  int64_t sum = 0;
  for (int i = 1; i < n + 1; ++i) {
    std::cin >> seq[i];
  }
  for (int i = 1; i < n + 1; ++i) {
    count_increase_seq[i] = 1;
  }

  for (int i = 2; i < n + 1; ++i) {
    for (int j = 1; j < i; ++j) {
      if (seq[i] > seq[j]) {
        count_increase_seq[i] += count_increase_seq[j] % kMod;
      }
    }
  }
  for (int i = 1; i < n + 1; ++i) {
    sum += count_increase_seq[i] % kMod;
  }

  std::cout << sum % kMod;
  return 0;
}