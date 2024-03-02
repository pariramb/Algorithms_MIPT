#include <cstring>
#include <iostream>

#define MAX_ACTIONS 1000000

int main() {
  char algorithm[MAX_ACTIONS];
  int k;
  std::cin >> k;
  char symbol;
  int len = 0;
  uint64_t count_of_scripts = 0;
  while (std::cin >> symbol) {
    if (symbol == '\\') {
      break;
    }
    algorithm[len] = symbol;
    ++len;
  }
  for (int i = 0; i < len - k; ++i) {
    uint64_t counter = 0;
    if (algorithm[i] == algorithm[i + k]) {
      int j = i + k;
      while ((j < len) && (algorithm[j] == algorithm[j - k])) {
        counter += 1;
        ++j;
      }
      i = j - k;
    }
    count_of_scripts += (counter * (1 + counter)) / 2;
  }
  std::cout << count_of_scripts;

  return 0;
}