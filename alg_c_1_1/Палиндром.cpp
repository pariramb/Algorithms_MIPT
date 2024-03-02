#include <cctype>
#include <iostream>

#define MAX_SIZE 100000

bool Change(char* begin, const char* end) {
  int mid = (end - begin) / 2;
  int counter = 0;
  for (int i = 0; i < mid; ++i) {
    if (*(begin + i) != *(end - 1 - i)) {
      counter += 1;
      if (counter == 2) {
        return false;
      }
    }
  }
  if (counter == 0) {
    return true;
  }
  if (counter == 1) {
    for (int i = 0; i < mid; ++i) {
      if (*(begin + i) != *(end - 1 - i)) {
        *(begin + i) = *(end - 1 - i);
        return true;
      }
    }
  }
  return false;
}
int Delete(const char* begin, const char* end) {
  int mid = (end - begin) / 2;
  const char* new_begin;
  const char* new_end;
  int counter = 0;
  for (int j = 0; j < mid; ++j) {
    if (*(begin + j) != *((end - 1) - j)) {
      if ((*(begin + j) != *((end - 1) - j - 1)) & (*(begin + j + 1) != *((end - 1) - j))) {
        return -1;
      }
      if (*(begin + j) == *((end - 1) - j - 1)) {
        new_end = (end - 1) - j;
        new_begin = begin + j;
        int mid = (new_end - new_begin) / 2;
        for (int i = 0; i < mid; ++i) {
          if (*(new_begin + i) != *((new_end - 1) - i)) {
            counter += 1;
            break;
          }
        }
        if (counter == 0) {
          return ((end - begin) - 1) - j;
        }
      }
      if (*(begin + j + 1) == *((end - 1) - j)) {
        new_begin = begin + j + 1;
        new_end = (end - 1) - j + 1;
        int mid = (new_end - new_begin) / 2;
        for (int i = 0; i < mid; ++i) {
          if (*(new_begin + i) != *((new_end - 1) - i)) {
            return -1;
          }
        }
        return j;
      }
    }
  }
  return -1;
}

int main() {
  char possible_palindrom[MAX_SIZE];
  int size = 0;
  char letter;
  while (std::cin >> letter) {
    if (letter == '\n') {
      possible_palindrom[size] = '\n';
      break;
    }
    if (isalpha(letter)) {
      possible_palindrom[size++] = toupper(letter);
    }
  }
  bool palindrom_after_change = Change(possible_palindrom, possible_palindrom + size);
  if (palindrom_after_change) {
    std::cout << "YES\n" << possible_palindrom;
  } else {
    int index_to_delete = Delete(possible_palindrom, possible_palindrom + size);
    if (index_to_delete != -1) {
      std::cout << "YES\n";
      for (int i = 0; i < index_to_delete; ++i) {
        std::cout << possible_palindrom[i];
      }
      for (int i = index_to_delete + 1; i < size; ++i) {
        std::cout << possible_palindrom[i];
      }
    } else {
      std::cout << "NO";
    }
  }
}