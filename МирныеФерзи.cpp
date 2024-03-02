#include <iostream>

#define ZERO_ROW 0

bool ColumnCheck(int j, int i, int* const placements_ferzi) {
  int* placements_ferzi_temp = placements_ferzi;
  while (placements_ferzi_temp != placements_ferzi + i) {
    if (*placements_ferzi_temp == j) {
      return false;
    }
    ++placements_ferzi_temp;
  }
  return true;
}
bool DiagCheck1(int j, int i, int* const placements_ferzi) {
  int* placements_ferzi_temp = placements_ferzi + i - 1;
  while ((j >= 0) && (placements_ferzi_temp != placements_ferzi - 1)) {
    if (*placements_ferzi_temp == j) {
      return false;
    }
    --placements_ferzi_temp;
    --j;
  }
  return true;
}
bool DiagCheck2(int j, int n, int i, int* const placements_ferzi) {
  int* placements_ferzi_temp = placements_ferzi + i - 1;
  while ((j < n) && (placements_ferzi_temp != placements_ferzi - 1)) {
    if (*placements_ferzi_temp == j) {
      return false;
    }
    --placements_ferzi_temp;
    ++j;
  }
  return true;
}
void PlacementsCount(int i, int* const placements_ferzi, int n, int& counter) {
  if (i == n) {
    counter += 1;
    return;
  }
  for (int j = 0; j < n; ++j) {
    if (i == 0) {
      *(placements_ferzi + i) = j;
      PlacementsCount(i + 1, placements_ferzi, n, counter);
    } else {
      if (ColumnCheck(j, i, placements_ferzi) && DiagCheck1(j - 1, i, placements_ferzi) &&
          DiagCheck2(j + 1, n, i, placements_ferzi)) {
        *(placements_ferzi + i) = j;
        PlacementsCount(i + 1, placements_ferzi, n, counter);
      }
    }
  }
}
int main() {
  int n;
  int counter = 0;
  std::cin >> n;
  auto const placements_ferzi = new int[n];  //массив под индексом i(строка) хранит j (столбец с ферзём)
  PlacementsCount(ZERO_ROW, placements_ferzi, n, counter);
  std::cout << counter;
  delete[] placements_ferzi;
  return 0;
}