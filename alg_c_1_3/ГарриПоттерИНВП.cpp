#include <algorithm>
#include <iostream>

void LISSequence(int temp, int* prev, int* seq) {
  if (temp != -1) {
    LISSequence(prev[temp], prev, seq);
    std::cout << seq[temp] << ' ';
  }
}

void BuildLIS(int* lis, size_t size, int* pos, int* seq, int* prev, int& len) {
  int* position;
  for (size_t i = 1; i < size; ++i) {
    position = std::upper_bound(lis, lis + size, seq[i]);
    if ((lis[position - lis - 1] < seq[i]) && (seq[i] < lis[position - lis])) {
      lis[position - lis] = seq[i];
      pos[position - lis] = i;
      prev[i] = pos[position - lis - 1];
    }
    len = std::max(len, static_cast<int>(position - lis));
  }
}

int main() {
  size_t n;
  std::cin >> n;
  enum { kMaxSeqSize = 1001, kINF = 10001, kEMPTY = -1 };
  int seq[kMaxSeqSize];
  int pos[kMaxSeqSize];
  int prev[kMaxSeqSize];
  int len = 0;
  int lis[kMaxSeqSize];
  pos[0] = kEMPTY;
  lis[0] = -kINF;
  for (size_t i = 1; i < n + 1; ++i) {
    lis[i] = kINF;
  }
  for (size_t i = 1; i < n + 1; ++i) {
    std::cin >> seq[i];
  }
  BuildLIS(lis, n + 1, pos, seq, prev, len);
  LISSequence(pos[len], prev, seq);
  return 0;
}