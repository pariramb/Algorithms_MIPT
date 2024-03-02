#include <iostream>

int main() {
  enum { kMaxSeqSize = 10000, kEMPTYSYMBOL = '8' };
  int size = 0;
  char seq1[kMaxSeqSize]{};
  char seq2[kMaxSeqSize]{};
  seq1[0] = seq2[0] = kEMPTYSYMBOL;
  std::cin >> (seq1 + 1);
  while (seq1[size] != '\0') {
    ++size;
  }
  for (int i = 1; i < size; i++) {
    seq2[i] = seq1[size - i];
  }

  auto lcs = new int*[size];
  for (int i = 0; i < size; ++i) {
    lcs[i] = new int[size];
  }

  for (int i = 0; i < size; ++i) {
    lcs[0][i] = lcs[i][0] = 0;
  }

  for (int i = 1; i < size; ++i) {
    for (int j = 1; j < size; ++j) {
      if (seq2[i] == seq1[j]) {
        lcs[i][j] = lcs[i - 1][j - 1] + 1;
      } else {
        lcs[i][j] = std::max(lcs[i - 1][j], lcs[i][j - 1]);
      }
    }
  }
  std::cout << size - lcs[size - 1][size - 1] - 1;
  for (int l = 0; l < size; ++l) {
    delete[] lcs[l];
  }
  delete[] lcs;
  return 0;
}