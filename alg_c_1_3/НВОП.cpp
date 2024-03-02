#include <iostream>

enum { kMaxLen = 501 };

void RestoreGSIMatrix(size_t max_i, size_t max_j, int* seq1, size_t (*index_i)[kMaxLen], size_t (*index_j)[kMaxLen]);
void BuildGSIMatrix(int* seq1, int* seq2, size_t rows, size_t colums, size_t (*index_i)[kMaxLen],
                    size_t (*index_j)[kMaxLen], int (*gsi_matrix)[kMaxLen]);

int main() {
  int seq1[kMaxLen];
  int seq2[kMaxLen];
  size_t m, n;
  std::cin >> n;
  for (size_t i = 1; i < n + 1; ++i) {
    std::cin >> seq1[i];
  }
  std::cin >> m;
  for (size_t i = 1; i < m + 1; ++i) {
    std::cin >> seq2[i];
  }
  int gsi_matrix[kMaxLen][kMaxLen]{};
  size_t index_i[kMaxLen][kMaxLen]{};
  size_t index_j[kMaxLen][kMaxLen]{};
  BuildGSIMatrix(seq1, seq2, n + 1, m + 1, index_i, index_j, gsi_matrix);
  size_t max_i = 1;
  for (size_t i = 1; i < n + 1; ++i) {
    if (gsi_matrix[max_i][m] < gsi_matrix[i][m]) {
      max_i = i;
    }
  }
  std::cout << gsi_matrix[max_i][m] << '\n';
  RestoreGSIMatrix(max_i, m, seq1, index_i, index_j);
  return 0;
}

void BuildGSIMatrix(int* seq1, int* seq2, size_t rows, size_t colums, size_t (*index_i)[kMaxLen],
                    size_t (*index_j)[kMaxLen], int (*gsi_matrix)[kMaxLen]) {
  for (size_t i = 1; i < rows; ++i) {
    for (size_t j = 1; j < colums; ++j) {
      if (seq1[i] == seq2[j]) {
        gsi_matrix[i][j] = 1;
        index_j[i][j] = j;
        for (size_t k = 1; k < i; ++k) {
          if ((seq1[k] < seq1[i]) && (gsi_matrix[i][j] < gsi_matrix[k][j] + 1)) {
            gsi_matrix[i][j] = gsi_matrix[k][j] + 1;
            index_i[i][j] = k;
            index_j[i][j] = j;
          }
        }
      } else {
        gsi_matrix[i][j] = gsi_matrix[i][j - 1];
        index_i[i][j] = i;
        index_j[i][j] = j - 1;
      }
    }
  }
}

void RestoreGSIMatrix(size_t max_i, size_t max_j, int* seq1, size_t (*index_i)[kMaxLen], size_t (*index_j)[kMaxLen]) {
  if ((max_i != 0) && (max_j != 0)) {
    if (index_j[max_i][max_j] == max_j) {
      RestoreGSIMatrix(index_i[max_i][max_j], index_j[max_i][max_j], seq1, index_i, index_j);
      std::cout << seq1[max_i] << ' ';
    } else {
      RestoreGSIMatrix(index_i[max_i][max_j], index_j[max_i][max_j], seq1, index_i, index_j);
    }
  }
}
