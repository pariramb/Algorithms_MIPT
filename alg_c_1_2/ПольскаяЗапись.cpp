#include <iostream>
#include <cctype>

class Stack {
  struct Node {
    int64_t value;
    Node* next;
  };
  size_t size_ = 0;
  Node* top_ = nullptr;
  Node* end_ = nullptr;

 public:
  void Push(int64_t value) {
    ++size_;
    if (top_ == nullptr) {
      top_ = new Node;
      top_->value = value;
      top_->next = nullptr;
      end_ = top_;
    } else {
      Node* top_temp = top_;
      top_ = new Node;
      top_->value = value;
      top_->next = top_temp;
    }
  }
  void Pop() {
    if (top_ != nullptr) {
      --size_;
      Node* top_temp = top_->next;
      delete top_;
      top_ = top_temp;
      if (top_ == nullptr) {
        end_ = top_;
      }
    }
  }
  int64_t Front() {
    if (top_ != nullptr) {
      return top_->value;
    }
    return -1;
  }
  int64_t Back() {
    if (end_ != nullptr) {
      return end_->value;
    }
    return -1;
  }
  size_t Size() {
    return size_;
  }
  void Clear() {
    while (top_ != nullptr) {
      Pop();
    }
  }
};

int main() {
  Stack expression;
  char symbol;
  int64_t first;
  int64_t second;
  while (std::cin >> symbol) {
    if (isdigit(symbol)) {
      expression.Push(symbol - '0');
      continue;
    }
    first = expression.Front();
    expression.Pop();
    second = expression.Front();
    expression.Pop();
    if (symbol == '+') {
      expression.Push(first + second);
    } else if (symbol == '-') {
      expression.Push(second - first);
    } else {
      expression.Push(first * second);
    }
  }
  std::cout << expression.Front();
  expression.Clear();
}