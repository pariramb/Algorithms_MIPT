#include <iostream>

#define MAX_SIZE 500000

template <class T>
uint64_t Merge(T* first_begin, T* first_end, T* second_begin, T* second_end) {
  uint64_t counter = 0;
  T* first_temp = first_begin;
  T* second_temp = second_begin;
  int i = 0;
  auto temp_sorted_array = new T[second_end - first_begin];
  while ((first_temp < first_end) && (second_temp < second_end)) {
    if (*second_temp < *first_temp) {
      *(temp_sorted_array + i++) = *second_temp++;
    } else {
      counter += second_temp - second_begin;
      *(temp_sorted_array + i++) = *first_temp++;
    }
  }
  while (first_temp < first_end) {
    counter += second_end - second_begin;
    *(temp_sorted_array + i++) = *first_temp++;
  }
  while (second_temp < second_end) {
    *(temp_sorted_array + i++) = *second_temp++;
  }
  for (int i = 0; i < (second_end - first_begin); i++) {
    first_begin[i] = temp_sorted_array[i];
  }
  delete[] temp_sorted_array;
  return counter;
}

template <class T>
uint64_t MergeSort(T* begin, T* end) {
  if (end - begin != 1) {
    T* mid = begin + (end - begin) / 2;
    return MergeSort(begin, mid) + MergeSort(mid, end) + Merge(begin, mid, mid, end);
  }
  return 0;
}

int main() {
  int a[MAX_SIZE];
  int size;
  std::cin >> size;
  for (int i = 0; i < size; ++i) {
    std::cin >> a[i];
  }
  std::cout << MergeSort(a, a + size);
  return 0;
}