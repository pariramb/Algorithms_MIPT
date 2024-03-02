#include <iostream>

class Stack {
  struct Node {
    char skobka;
    Node* next;
  };
  size_t size_ = 0;
  Node* top_ = nullptr;
  Node* end_ = nullptr;

 public:
  void Push(char skobka) {
    ++size_;
    if (top_ == nullptr) {
      top_ = new Node;
      top_->skobka = skobka;
      top_->next = nullptr;
      end_ = top_;
    } else {
      Node* top_temp = top_;
      top_ = new Node;
      top_->skobka = skobka;
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
  char Front() {
    if (top_ != nullptr) {
      return top_->skobka;
    }
    return 'd';
  }
  char Back() {
    if (end_ != nullptr) {
      return end_->skobka;
    }
    return 'a';
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
  Stack skob_posled;
  char symbol;
  while (std::cin >> symbol) {
    if ((symbol == '(') || (symbol == '[') || (symbol == '{') || (skob_posled.Size() == 0)) {
      skob_posled.Push(symbol);
      continue;
    }
    char last_el = skob_posled.Front();
    bool find_same = ((symbol == ')') && (last_el == '(')) || ((symbol == ']') && (last_el == '[')) ||
                     ((symbol == '}') && (last_el == '{'));
    if (find_same) {
      skob_posled.Pop();
    } else {
      skob_posled.Push(symbol);
    }
  }
  if (skob_posled.Size() == 0) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  skob_posled.Clear();
}