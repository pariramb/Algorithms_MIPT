#include <iostream>

#define MAX_SIZE 100000

void AddElements(int* array, int size) {
  for (int i = 0; i < size; ++i) {
    std::cin >> array[i];
  }
}

template <class T>
void Swap(T& a, T& b) {
  T a_temp = a;
  a = b;
  b = a_temp;
}

template <class T>
T* Partition(T* begin, T* end) {
  T pivot_value = *(begin + (end - begin) / 2);
  T* begin_temp = begin;
  T* end_temp = end;
  while (begin_temp <= end_temp) {
    while (*begin_temp < pivot_value) {
      ++begin_temp;
    }
    while (pivot_value < *end_temp) {
      --end_temp;
    }
    if ((end_temp < begin_temp) | (end_temp == begin_temp)) {
      break;
    }
    Swap(*begin_temp, *end_temp);
    ++begin_temp;
    --end_temp;
  }
  return end_temp;
}

template <class T>
void QuickSort(T* begin, T* end) {
  if (begin >= end) {
    return;
  }
  T* pivot = Partition(begin, end);
  QuickSort(begin, pivot);
  QuickSort(pivot + 1, end);
}

int main() {
  int size1;
  int size2;
  int array1[MAX_SIZE];
  int array2[MAX_SIZE];
  std::cin >> size1;
  AddElements(array1, size1);
  std::cin >> size2;
  AddElements(array2, size2);
  QuickSort(array1, array1 + size1 - 1);
  QuickSort(array2, array2 + size2 - 1);
  bool same = true;
  int* array1_temp = array1;
  int* array2_temp = array2;
  while ((array1_temp < array1 + size1 - 1) && (array2_temp < array2 + size2 - 1)) {
    if (*array1_temp != *array2_temp) {
      same = false;
      break;
    }
    ++array1_temp;
    ++array2_temp;
    while ((*array1_temp == *(array1_temp - 1)) && (array1_temp < array1 + size1)) {
      ++array1_temp;
    }
    while ((*array2_temp == *(array2_temp - 1)) && (array2_temp < array2 + size2)) {
      ++array2_temp;
    }
  }
  if (*(array1 + size1 - 1) != *(array2 + size2 - 1)) {
    same = false;
  }
  if (same) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }

  return 0;
}