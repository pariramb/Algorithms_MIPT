#ifndef STRING_VIEW_H_
#define STRING_VIEW_H_

#include <stdexcept>

class StringViewOutOfRange : public std::out_of_range {
 public:
  StringViewOutOfRange() : std::out_of_range("StringViewOutOfRange") {
  }
};

class StringView {
  const char* string_;
  size_t size_ = 0;

 public:
  StringView() {
    string_ = nullptr;
  }
  StringView(const char* str) {  // NOLINT
    string_ = str;
    const char* string_temp = string_;
    while (*string_temp != '\0') {
      ++size_;
      ++string_temp;
    }
  }

  StringView(const char* str, size_t size) : string_(str), size_(size) {
  }

  const char& operator[](size_t i) const {
    return string_[i];
  }

  const char& At(size_t idx) const {
    if (idx < size_) {
      return string_[idx];
    }
    throw StringViewOutOfRange{};
  }

  const char& Back() const {
    return string_[size_ - 1];
  }

  const char& Front() const {
    return string_[0];
  }
  size_t Size() const {
    return size_;
  }
  size_t Length() const {
    return size_;
  }
  bool Empty() const {
    return size_ == 0;
  }
  const char* Data() const {
    return string_;
  }
  void Swap(StringView& other) {
    std::swap(string_, other.string_);
    std::swap(size_, other.size_);
  }
  void RemovePrefix(size_t prefix_size) {
    string_ += prefix_size;
    size_ -= prefix_size;
  }
  void RemoveSuffix(size_t suffix_size) {
    size_ -= suffix_size;
  }
  StringView Substr(size_t pos, size_t count = -1) {
    if (Size() - pos <= 0) {
      throw StringViewOutOfRange{};
    }
    return StringView(string_ + pos, std::min(count, Size() - pos));
  }
};
#endif