#include <iostream>

#define MAX_SUM_SIZES 1'000'000
#define MAX_K 10000
#define MIN_VALUE 1'000'000'000

template <class T>
void Merge(T* first_begin, T* first_end, T* second_begin, T* second_end, T* result_temp) {
  T* first_temp = first_begin;
  T* second_temp = second_begin;
  int i = 0;
  while ((first_temp < first_end) && (second_temp < second_end)) {
    if (*second_temp < *first_temp) {
      result_temp[i++] = *second_temp++;
    } else {
      result_temp[i++] = *first_temp++;
    }
  }
  while (first_temp < first_end) {
    result_temp[i++] = *first_temp++;
  }
  while (second_temp < second_end) {
    result_temp[i++] = *second_temp++;
  }
  for (int i = 0; i < (second_end - first_begin); i++) {
    first_begin[i] = result_temp[i];
  }
}

template <class T>
void MergeSortK(T** begin, T** end, T* result_temp) {
  if (end - begin == 2) {
    Merge(*begin, *(begin + 1), *(begin + 1), *end, result_temp);
  } else {
    if (end - begin != 1) {
      T k = (end - begin) / 2;
      T** mid = begin + k;
      MergeSortK(begin, mid, result_temp);
      MergeSortK(mid, end, result_temp);
      Merge(*begin, *mid, *mid, *end, result_temp);
    }
  }
}
int main() {
  int n, k;
  int sum = 0;
  std::cin >> k;
  int* pointers[MAX_K];
  int result[MAX_SUM_SIZES];
  int result_temp[MAX_SUM_SIZES];
  int j = 0;
  int last_value = MIN_VALUE + 1;
  int count_pointers = 0;
  for (int i = 0; i < k; ++i) {
    std::cin >> n;
    sum += n;
    int jj = j + n;
    while (j < jj) {
      std::cin >> result[j];
      ++j;
    }
    if ((n != 0) && (last_value > result[jj - n])) {
      pointers[count_pointers] = &result[jj - n];
      ++count_pointers;
    }
    if (j > 0) {
      last_value = result[j - 1];
    }
  }
  result[j] = 0;
  pointers[count_pointers] = &result[j];
  MergeSortK(pointers, pointers + count_pointers, result_temp);
  for (int i = 0; i < sum; i++) {
    std::cout << result[i] << ' ';
  }
}