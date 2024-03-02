#include <iostream>

class Dec {
  struct Node {
    int64_t value;
    Node* prev;
    Node* next;
  };
  size_t size_ = 0;
  Node* begin_ = nullptr;
  Node* end_ = nullptr;

 public:
  void PushFront(int value) {
    ++size_;
    if (begin_ == nullptr) {
      begin_ = new Node;
      begin_->value = value;
      begin_->prev = nullptr;
      begin_->next = nullptr;
      end_ = begin_;
    } else {
      Node* begin__temp = begin_;
      begin_ = new Node;
      begin_->value = value;
      begin_->prev = nullptr;
      begin_->next = begin__temp;
      begin__temp->prev = begin_;
    }
  }
  void PushBack(int value) {
    ++size_;
    if (end_ == nullptr) {
      end_ = new Node;
      end_->value = value;
      end_->prev = nullptr;
      end_->next = nullptr;
      begin_ = end_;
    } else {
      Node* end__temp = end_;
      end_ = new Node;
      end_->value = value;
      end_->next = nullptr;
      end_->prev = end__temp;
      end__temp->next = end_;
    }
  }
  void PopFront() {
    if (begin_ != nullptr) {
      --size_;
      Node* begin__temp = begin_->next;
      delete begin_;
      begin_ = begin__temp;
      if (begin_ != nullptr) {
        begin_->prev = nullptr;
      } else {
        end_ = nullptr;
      }
    }
  }
  void PopBack() {
    if (end_ != nullptr) {
      --size_;
      Node* end__temp = end_->prev;
      delete end_;
      end_ = end__temp;
      if (end_ != nullptr) {
        end_->next = nullptr;
      } else {
        begin_ = nullptr;
      }
    }
  }
  int Front() {
    if (begin_ != nullptr) {
      return begin_->value;
    }
    return 0;
  }
  int Back() {
    if (end_ != nullptr) {
      return end_->value;
    }
    return 0;
  }
  size_t Size() {
    return size_;
  }
  void Clear() {
    if (size_ != 0) {
      while (size_ != 1) {
        --size_;
        Node* end__temp = end_->prev;
        delete end_;
        end_ = end__temp;
      }
      --size_;
      delete end_;
      end_ = nullptr;
      begin_ = nullptr;
    }
  }
};
int main() {
  enum { kMaxLenCommand = 20, kFirstWord = 1, kSecondWordPush = 5, kSecondWordPop = 4 };
  int k;
  std::cin >> k;
  Dec dec;
  char command[kMaxLenCommand];
  int number;
  for (int i = 0; i < k; ++i) {
    std::cin >> command;
    switch (command[kFirstWord]) {
      case 'r':
        if (dec.Size() != 0) {
          std::cout << dec.Front() << '\n';
        } else {
          std::cout << "error" << '\n';
        }
        break;
      case 'a':
        if (dec.Size() != 0) {
          std::cout << dec.Back() << '\n';
        } else {
          std::cout << "error" << '\n';
        }
        break;
      case 'i':
        std::cout << dec.Size() << '\n';
        break;
      case 'l':
        dec.Clear();
        std::cout << "ok\n";
        break;
      case 'x':
        dec.Clear();
        std::cout << "bye";
        break;
      case 'u':
        std::cin >> number;
        if (command[kSecondWordPush] == 'f') {
          dec.PushFront(number);
        } else {
          dec.PushBack(number);
        }
        std::cout << "ok\n";
        break;
      case 'o':
        if (dec.Size() == 0) {
          std::cout << "error\n";
          break;
        }
        if (command[kSecondWordPop] == 'f') {
          std::cout << dec.Front() << "\n";
          dec.PopFront();
        } else {
          std::cout << dec.Back() << "\n";
          dec.PopBack();
        }
        break;
    }
    if (command[kFirstWord] == 'x') {
      break;
    }
  }
  dec.Clear();
}