#include <iostream>

#define MAX_FIELD 10 + 1 + 1  //с учётом рамки вокруг поля
#define CONDITION_1 2
#define CONDITION_2 3
#define ONE_MICROBE 1
#define NO_MICROBE 0

using std::cin;
using std::cout;

int NumberOfNeibours(int i, int j, int (*ptr_square)[MAX_FIELD]);
int AfterOneSec(int i, int j, int (*ptr_square)[MAX_FIELD]);

int NumberOfNeibours(int i, int j, int (*ptr_square)[MAX_FIELD]) {
  return ptr_square[i][j + 1] + ptr_square[i][j - 1] + ptr_square[i - 1][j - 1] + ptr_square[i - 1][j + 1] +
         ptr_square[i - 1][j] + ptr_square[i + 1][j - 1] + ptr_square[i + 1][j + 1] + ptr_square[i + 1][j];
}

int AfterOneSec(int i, int j, int (*ptr_square)[MAX_FIELD]) {
  int number_of_neibours = NumberOfNeibours(i, j, ptr_square);
  if ((ptr_square[i][j] == ONE_MICROBE) && ((number_of_neibours < CONDITION_1) || (number_of_neibours > CONDITION_2))) {
    return 0;
  }
  if ((ptr_square[i][j] == NO_MICROBE) && ((number_of_neibours == CONDITION_2))) {
    return 1;
  }
  return ptr_square[i][j];
}

int main() {
  int size_of_square, time;
  cin >> size_of_square >> time;
  int square[MAX_FIELD][MAX_FIELD]{};
  int(*ptr_square)[MAX_FIELD] = square;
  int new_square[MAX_FIELD][MAX_FIELD]{};
  int(*ptr_new_square)[MAX_FIELD] = new_square;
  for (int i = 1; i < size_of_square + 1; ++i) {
    for (int j = 1; j < size_of_square + 1; ++j) {
      cin >> square[i][j];
    }
  }
  for (int time_now = 0; time_now < time; ++time_now) {
    for (int i = 1; i < size_of_square + 1; ++i) {
      for (int j = 1; j < size_of_square + 1; ++j) {
        ptr_new_square[i][j] = AfterOneSec(i, j, ptr_square);
      }
    }
    std::swap(ptr_square, ptr_new_square);
  }
  for (int i = 1; i < size_of_square + 1; ++i) {
    for (int j = 1; j < size_of_square + 1; ++j) {
      cout << ptr_square[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}