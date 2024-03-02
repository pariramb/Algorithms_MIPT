#include <algorithm>
#include <iostream>

int main() {
  int n;
  std::cin >> n;
  enum { kMaxSeqSize = 100001, kINF = 100001 };
  int seq[kMaxSeqSize];
  int len = 0;
  int lis[kMaxSeqSize];
  int* j;
  lis[0] = -kINF;
  for (int i = 1; i < n + 1; ++i) {
    lis[i] = kINF;
  }
  for (int i = 1; i < n + 1; ++i) {
    std::cin >> seq[i];
  }
  int a;
  for (int i = 1; i < n + 1; ++i) {
    j = std::lower_bound(lis, lis + n + 1, seq[i]);
    if ((lis[j - lis - 1] < seq[i]) && (seq[i] < lis[j - lis])) {
      lis[j - lis] = seq[i];
    }
    a = (j - lis);
    len = std::max(len, a);
  }
  std::cout << len;
  return 0;
}