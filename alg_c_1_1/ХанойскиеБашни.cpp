#include <iostream>

using std::cin;
using std::cout;

#define KUDA 3
#define OTKUDA 1
#define SUM 1 + 2 + 3  //сумма номеров столбцов

void VseShagi(int high, int otkuda, int kuda);

void VseShagi(int high, int otkuda, int kuda) {
  if (high == 1) {
    cout << high << ' ' << otkuda << ' ' << kuda << '\n';
  } else {
    VseShagi(high - 1, otkuda, SUM - otkuda - kuda);
    cout << high << ' ' << otkuda << ' ' << kuda << '\n';
    VseShagi(high - 1, SUM - otkuda - kuda, kuda);
  }
}

int main() {
  int high;
  cin >> high;
  VseShagi(high, OTKUDA, KUDA);
  return 0;
}