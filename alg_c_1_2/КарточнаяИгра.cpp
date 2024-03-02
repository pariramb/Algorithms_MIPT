#include <iostream>

class Queue {
  struct Node {
    int value;
    Node* next;
  };
  size_t size_ = 0;
  Node* top_ = nullptr;
  Node* end_ = nullptr;

 public:
  void Push(int value) {
    ++size_;
    if (end_ == nullptr) {
      end_ = new Node;
      end_->value = value;
      end_->next = nullptr;
      top_ = end_;
    } else {
      Node* end_temp = end_;
      end_ = new Node;
      end_->value = value;
      end_->next = nullptr;
      end_temp->next = end_;
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
  int Front() {
    if (top_ != nullptr) {
      return top_->value;
    }
    return 0;
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
  Queue coloda1;
  Queue coloda2;
  int counter = 0;
  int value;
  enum { kBotva = 1000000 };
  for (int i = 0; i < 5; ++i) {
    std::cin >> value;
    coloda1.Push(value);
  }
  for (int i = 0; i < 5; ++i) {
    std::cin >> value;
    coloda2.Push(value);
  }
  while ((coloda1.Size() != 0) && (coloda2.Size() != 0)) {
    ++counter;
    if (counter == kBotva) {
      break;
    }
    int a = coloda1.Front() - coloda2.Front();
    if (((a > 0) && (a < 9)) || (-a == 9)) {
      coloda1.Push(coloda1.Front());
      coloda1.Push(coloda2.Front());
      coloda2.Pop();
      coloda1.Pop();
    } else {
      coloda2.Push(coloda1.Front());
      coloda2.Push(coloda2.Front());
      coloda2.Pop();
      coloda1.Pop();
    }
  }
  if (coloda1.Size() == 0) {
    std::cout << "second " << counter;
  } else if (coloda2.Size() == 0) {
    std::cout << "first " << counter;
  } else {
    std::cout << "botva";
  }
  coloda1.Clear();
  coloda2.Clear();
}