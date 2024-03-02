#include <iostream>

int main() {
  int x, y, h, w;
  int coordinatex = 0;
  int coordinatey = 0;
  std::cin >> x >> y >> h >> w;
  auto s = new int*[x];
  for (int i = 0; i < x; ++i) {
    s[i] = new int[y];
  }
  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < y; ++j) {
      std::cin >> s[i][j];
    }
  }
  for (int i = 0; i < x;) {
    for (int j = 0; j < y;) {
      for (int k = i; (k < i + h) && (k < x); ++k) {
        for (int l = j; (l < j + w) && (l < y); ++l) {
          if (s[k][l] >= s[coordinatex][coordinatey]) {
            coordinatex = k;
            coordinatey = l;
          }
        }
      }
      if ((i != coordinatex) || (j != coordinatey)) {
        i = coordinatex;
        j = coordinatey;
      } else {
        std::cout << coordinatex << ' ' << coordinatey;
        for (int i = 0; i < x; ++i) {
          delete[] s[i];
        }
        delete[] s;
        return 0;
      }
    }
  }
  std::cout << coordinatex << ' ' << coordinatey;
  for (int i = 0; i < x; ++i) {
    delete[] s[i];
  }
  delete[] s;
  return 0;
}