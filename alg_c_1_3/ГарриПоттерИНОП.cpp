#include <iostream>

void BuildLCSMatrix(int** lcs_matrix, int* seq1, int* seq2, size_t rows, size_t colums) {
  for (size_t i = 0; i < colums; ++i) {
    lcs_matrix[0][i] = 0;
  }

  for (size_t i = 0; i < rows; ++i) {
    lcs_matrix[i][0] = 0;
  }

  for (size_t i = 1; i < rows; ++i) {
    for (size_t j = 1; j < colums; ++j) {
      if (seq1[i] == seq2[j]) {
        lcs_matrix[i][j] = lcs_matrix[i - 1][j - 1] + 1;
      } else {
        lcs_matrix[i][j] = std::max(lcs_matrix[i - 1][j], lcs_matrix[i][j - 1]);
      }
    }
  }
}

void RestoreLCS(int** lcs_matrix, int* seq1, int* seq2, size_t i, size_t j) {
  if ((i > 0) && (j > 0)) {
    if (seq1[i] == seq2[j]) {
      RestoreLCS(lcs_matrix, seq1, seq2, i - 1, j - 1);
      std::cout << seq1[i] << ' ';
    } else {
      if (std::max(lcs_matrix[i][j - 1], lcs_matrix[i - 1][j]) == lcs_matrix[i][j - 1]) {
        RestoreLCS(lcs_matrix, seq1, seq2, i, j - 1);
      } else {
        RestoreLCS(lcs_matrix, seq1, seq2, i - 1, j);
      }
    }
  }
}

void InputSeq(int* seq, size_t size) {
  for (size_t i = 1; i < size + 1; ++i) {
    std::cin >> seq[i];
  }
}

int main() {
  enum { kMaxSeqSize = 1001 };
  size_t n, m;
  int seq1[kMaxSeqSize];
  int seq2[kMaxSeqSize];
  std::cin >> n;
  InputSeq(seq1, n);
  std::cin >> m;
  InputSeq(seq2, m);
  auto lcs_matrix = new int*[n + 1];
  for (size_t i = 0; i < n + 1; ++i) {
    lcs_matrix[i] = new int[m + 1];
  }
  BuildLCSMatrix(lcs_matrix, seq1, seq2, n + 1, m + 1);
  RestoreLCS(lcs_matrix, seq1, seq2, n, m);
  for (size_t l = 0; l < n + 1; ++l) {
    delete[] lcs_matrix[l];
  }
  delete[] lcs_matrix;
  return 0;
}