#include <iostream>

int Max(int a, int b) {
  return (a > b ? a : b);
}
int main() {
  int n;
  std::cin >> n;
  int64_t max_size = 0;
  int w, h;
  for (int i = 0; i < n; ++i) {
    std::cin >> w;
    std::cin >> h;
    max_size += std::max(w, h);
  }
  std::cout << max_size;
  return 0;
}