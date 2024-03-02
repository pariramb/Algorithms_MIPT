#include <iostream>

int main() {
  uint64_t w, h, n;
  std::cin >> w >> h >> n;
  uint64_t a_min1, a_min2, a_min3, a_min4;
  uint64_t photos_on_width = 1;
  uint64_t photos_on_heigth = n / photos_on_width + bool(n % photos_on_width);
  while (w * photos_on_width < h * photos_on_heigth) {
    a_min1 = h * photos_on_heigth;
    ++photos_on_width;
    photos_on_heigth = n / photos_on_width + bool(n % photos_on_width);
  }
  a_min2 = w * photos_on_width;
  photos_on_heigth = 1;
  photos_on_width = n / photos_on_heigth + bool(n % photos_on_heigth);

  while (h * photos_on_heigth < w * photos_on_width) {
    a_min3 = w * photos_on_width;
    ++photos_on_heigth;
    photos_on_width = n / photos_on_heigth + bool(n % photos_on_heigth);
  }
  a_min4 = h * photos_on_heigth;
  a_min1 = std::min(a_min1, a_min2);
  a_min1 = std::min(a_min3, a_min4);
  std::cout << std::min(a_min1, a_min2);
}