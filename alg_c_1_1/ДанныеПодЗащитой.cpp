#include <iostream>

#define MAXLEN 100000

using std::cin;
using std::cout;

int main() {
  char str[MAXLEN];
  int len_of_str = 0;  //без учёта #
  while (cin >> str[len_of_str]) {
    if (str[len_of_str] == '#') {
      break;
    }
    ++len_of_str;
  }
  int mid = (len_of_str + 1) / 2;
  for (int i = 0; i < mid; ++i) {
    cout << str[2 * i];
  }
  if (len_of_str % 2 == 0) {
    for (int i = len_of_str - 1; i > 0; i -= 2) {
      cout << str[i];
    }
  } else {
    for (int i = len_of_str - 2; i > 0; i -= 2) {
      cout << str[i];
    }
  }
  return 0;
}