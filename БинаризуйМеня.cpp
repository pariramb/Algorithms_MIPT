#include <cctype>
#include <cmath>
#include <iostream>

#define MAX_SIZE 255

void Bin(char* number, int len) {
  int ostatok = 0;
  for (int i = 0; i < len; ++i) {
    int ostatok_temp = (number[i] % 2) * 10;
    number[i] = (number[i] + ostatok) / 2;
    ostatok = ostatok_temp;
  }
  if (number[0] == 0) {
    ++number;
    --len;
  }
  if (len > 0) {
    Bin(number, len);
  }
  std::cout << ostatok / 10;
}
int main() {
  char number_array[MAX_SIZE];
  char symbol;
  int len = 0;
  while (std::cin >> std::noskipws >> symbol) {
    if (isdigit(symbol)) {
      number_array[len] = symbol - '0';
      ++len;
      continue;
    }
    if (len != 0) {
      Bin(number_array, len);
      len = 0;
    }
    std::cout << symbol;
  }
  if (len != 0) {
    Bin(number_array, len);
    len = 0;
  }
  return 0;
}