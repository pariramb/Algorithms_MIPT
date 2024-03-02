#include <iostream>

int main() {
  enum { kMax = 5001, kEMPTYSYMBOL = '8' };
  size_t size1 = 0, size2 = 0;
  char seq1[kMax]{};
  char seq2[kMax]{};
  char* seq1_temp = seq1;
  char* seq2_temp = seq2;
  int temp_min;
  seq1[0] = seq2[0] = kEMPTYSYMBOL;
  std::cin >> (seq1 + 1);
  std::cin >> (seq2 + 1);
  while (*seq1_temp != '\0') {
    ++size1;
    ++seq1_temp;
  }
  while (*seq2_temp != '\0') {
    ++size2;
    ++seq2_temp;
  }
  auto lcs = new int*[size2];
  for (size_t i = 0; i < size2; ++i) {
    lcs[i] = new int[size1];
  }

  for (size_t i = 0; i < size1; ++i) {
    lcs[0][i] = i;
  }

  for (size_t i = 0; i < size2; ++i) {
    lcs[i][0] = i;
  }

  for (size_t i = 1; i < size2; ++i) {
    for (size_t j = 1; j < size1; ++j) {
      if (seq2[i] == seq1[j]) {
        lcs[i][j] = lcs[i - 1][j - 1];
      } else {
        temp_min = std::min(lcs[i - 1][j], lcs[i][j - 1]);
        lcs[i][j] = std::min(temp_min, lcs[i - 1][j - 1]) + 1;
      }
    }
  }
  std::cout << lcs[size2 - 1][size1 - 1];
  for (size_t l = 0; l < size2; ++l) {
    delete[] lcs[l];
  }
  delete[] lcs;
  return 0;
}