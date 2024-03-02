#ifndef R_H_
#define R_H_

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
  while ((begin_temp < end_temp) | (begin_temp == end_temp)) {
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
void KthElement(T* begin, T* kth, T* end) {
  if (begin >= (end - 1)) {
    return;
  }
  T* pivot = Partition(begin, (end - 1));
  if (kth < pivot) {
    KthElement(begin, kth, pivot + 1);
  } else {
    if (kth > pivot) {
      KthElement(pivot + 1, kth, end);
    }
  }
}
#endif