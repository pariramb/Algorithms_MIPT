#include <iostream>

class Stack {
  struct Node {
    int64_t value;
    int64_t min;
    Node* next;
  };
  size_t size_ = 0;
  Node* begin_ = nullptr;

 public:
  void Push(int64_t value) {
    ++size_;
    if (begin_ == nullptr) {
      begin_ = new Node;
      begin_->value = value;
      begin_->min = value;
      begin_->next = nullptr;
    } else {
      Node* begin_temp = begin_;
      begin_ = new Node;
      begin_->value = value;
      begin_->next = begin_temp;
      begin_->min = std::min(begin_temp->min, value);
    }
  }
  void Pop() {
    if (begin_ != nullptr) {
      --size_;
      Node* begin_temp = begin_->next;
      delete begin_;
      begin_ = begin_temp;
    }
  }
  int64_t Front() {
    if (begin_ != nullptr) {
      return begin_->value;
    }
    return 0;
  }
  size_t Size() {
    return size_;
  }
  void Clear() {
    while (size_ != 0) {
      Pop();
    }
  }
  int64_t Min() {
    if (begin_ != nullptr) {
      return begin_->min;
    }
    return 0;
  }
};

class DequeWithMin {
  Stack stack1_;
  Stack stack2_;

 public:
  void Enqueue(int64_t value) {
    stack1_.Push(value);
  }
  void Dequeue() {
    if (stack2_.Size() == 0) {
      while (stack1_.Size() != 0) {
        stack2_.Push(stack1_.Front());
        stack1_.Pop();
      }
    }
    stack2_.Pop();
  }
  int64_t Front() {
    if (stack2_.Size() == 0) {
      while (stack1_.Size() != 0) {
        stack2_.Push(stack1_.Front());
        stack1_.Pop();
      }
    }
    if (stack2_.Size() != 0) {
      return stack2_.Front();
    }
    return 0;
  }
  size_t Size() {
    return stack1_.Size() + stack2_.Size();
  }
  void Clear() {
    stack1_.Clear();
    stack2_.Clear();
  }
  int64_t Min() {
    if (stack1_.Size() == 0) {
      return stack2_.Min();
    }
    if (stack2_.Size() == 0) {
      return stack1_.Min();
    }
    return std::min(stack1_.Min(), stack2_.Min());
  }
};
int main() {
  int m;
  std::cin >> m;
  enum { kMaxSize = 8 };
  char command[kMaxSize];
  int64_t new_element;
  DequeWithMin deq;
  for (int i = 0; i < m; ++i) {
    std::cin >> command;
    switch (command[0]) {
      case 'e':
        std::cin >> new_element;
        deq.Enqueue(new_element);
        std::cout << "ok\n";
        break;
      case 'd':
        if (deq.Size() == 0) {
          std::cout << "error\n";
        } else {
          std::cout << deq.Front() << "\n";
          deq.Dequeue();
        }
        break;
      case 'f':
        if (deq.Size() == 0) {
          std::cout << "error\n";
        } else {
          std::cout << deq.Front() << "\n";
        }
        break;
      case 's':
        std::cout << deq.Size() << "\n";
        break;
      case 'c':
        deq.Clear();
        std::cout << "ok\n";
        break;
      case 'm':
        if (deq.Size() == 0) {
          std::cout << "error\n";
        } else {
          std::cout << deq.Min() << '\n';
        }
    }
  }
  deq.Clear();
  return 0;
}