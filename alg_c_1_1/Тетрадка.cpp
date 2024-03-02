#include <iostream>

#define MAX_SIZE 1000

const char* WhatType(int counter_horiz, int counter_vert, int space_horiz, int space_vert, int n, int m) {
  if ((counter_horiz > 0) && (counter_vert > 0) && ((counter_horiz != n) | (counter_vert != m))) {
    return "Square";
  }
  if ((counter_vert == 0) && (counter_horiz > 1) && (space_horiz < n)) {
    return "Line";
  }
  if ((counter_horiz == 0) && (counter_vert > 1) && (space_vert < n)) {
    return "Vertical line";
  }
  return "?";
}

int main() {
  int n, m;
  std::cin >> n >> m;
  char tetradka[MAX_SIZE][MAX_SIZE];
  int counter_horiz = 0;
  int space_horiz = 0;
  int last_index_of_horiz_line = 0;
  for (int i = 0; i < n; ++i) {
    int counter = 0;
    for (int j = 0; j < m; ++j) {
      std::cin >> tetradka[i][j];
      if (tetradka[i][j] == '1') {
        counter += 1;
      }
    }
    if (counter == m) {
      counter_horiz += 1;
      space_horiz = i - last_index_of_horiz_line;
      last_index_of_horiz_line = i;
    }
  }
  space_horiz = space_horiz - 1;  //от -1
  int counter_vert = 0;
  int space_vert = 0;
  int last_index_of_vert_line = 0;
  for (int j = 0; j < m; ++j) {
    int counter = 0;
    for (int i = 0; i < n; ++i) {
      if (tetradka[i][j] == '1') {
        counter += 1;
      }
    }
    if (counter == n) {
      counter_vert += 1;
      space_vert = j - last_index_of_vert_line;
      last_index_of_vert_line = j;
    }
  }
  space_vert = space_vert - 1;

  std::cout << WhatType(counter_horiz, counter_vert, space_horiz, space_vert, n, m);
  return 0;
}