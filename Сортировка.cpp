#ifndef MERGE_SORT_H_

#define MERGE_SORT_H_

template <class T>

void Merge(T* first_begin, T* first_end, T* second_begin, T* second_end) {
  T* first_temp = first_begin;
  T* second_temp = second_begin;
  int i = 0;
  auto temp_sorted_array = new T[second_end - first_begin];
  while ((first_temp < first_end) && (second_temp < second_end)) {
    if (*second_temp < *first_temp) {
      *(temp_sorted_array + i++) = *second_temp++;
    } else {
      *(temp_sorted_array + i++) = *first_temp++;
    }
  }
  while (first_temp < first_end) {
    *(temp_sorted_array + i++) = *first_temp++;
  }
  while (second_temp < second_end) {
    *(temp_sorted_array + i++) = *second_temp++;
  }
  for (int i = 0; i < (second_end - first_begin); i++) {
    first_begin[i] = temp_sorted_array[i];
  }
  delete[] temp_sorted_array;
}

template <class T>

void Sort(T* begin, T* end) {
  if (end - begin != 1) {
    T* mid = begin + (end - begin) / 2;
    Sort(begin, mid);
    Sort(mid, end);
    Merge(begin, mid, mid, end);
  }
}
#endif  // MERGE_SORT_H_