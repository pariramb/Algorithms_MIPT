#include <iostream>

void Put(int n);
void Clean(int n);

void Put(int n) {
  if (n == 1) {
    std::cout << 1 << ' ';
  } else {
    if (n == 2) {
      std::cout << 1 << ' ' << 2 << ' ';
    } else {
      Put(n - 1);
      Clean(n - 2);
      std::cout << n << ' ';
      Put(n - 2);
    }
  }
}

void Clean(int n) {
  if (n == 1) {
    std::cout << -1 << ' ';
  } else {
    if (n == 2) {
      std::cout << -2 << ' ' << -1 << ' ';
    } else {
      Clean(n - 2);
      std::cout << -n << ' ';
      Put(n - 2);
      Clean(n - 1);
    }
  }
}
int main() {
  int n;
  std::cin >> n;
  Put(n);
  return 0;
}