#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdexcept>

class ArrayOutOfRange : public std::out_of_range {
 public:
  ArrayOutOfRange() : std::out_of_range("ArrayOutOfRange") {
  }
};

template <class T, size_t N>
class Array {
 public:
  T array_[N];

  const T& operator[](size_t i) const {
    return array_[i];
  }

  T& operator[](size_t i) {
    return array_[i];
  }

  T& At(size_t idx) {
    if (idx < N) {
      return array_[idx];
    }
    throw ArrayOutOfRange{};
  }
  const T& At(size_t idx) const {
    if (idx < N) {
      return array_[idx];
    }
    throw ArrayOutOfRange{};
  }
  T& Front() {
    return array_[0];
  }
  const T& Front() const {
    return array_[0];
  }
  T& Back() {
    return array_[N - 1];
  }
  const T& Back() const {
    return array_[N - 1];
  }
  T* Data() {
    return array_;
  }
  const T* Data() const {
    return array_;
  }
  size_t Size() {
    return N;
  }
  size_t Size() const {
    return N;
  }
  bool Empty() const {
    return N == 0;
  }
  void Fill(const T& value) {
    std::fill(array_, array_ + N, value);
  }
  void Swap(Array<T, N>& other) {
    for (size_t i = 0; i < N; i++) {
      std::swap(array_[i], other[i]);
    }
  }
};
#endif