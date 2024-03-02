#include <iostream>

class Dec {
  struct Node {
    int64_t value;
    Node* prev;
    Node* next;
  };
  int size_ = 0;
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
  int Size() {
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
class Goblin {
  Dec stack1_;
  Dec stack2_;

 public:
  void Enqueue(int64_t value) {
    stack1_.PushFront(value);
  }
  int64_t Dequeue() {
    int64_t value;
    if (stack2_.Size() == 0) {
      value = stack1_.Back();
      stack1_.PopBack();
    } else {
      value = stack2_.Back();
      stack2_.PopBack();
    }
    return value;
  }

  void Clear() {
    stack1_.Clear();
    stack2_.Clear();
  }
  void Mid(int64_t value) {
    while (stack1_.Size() - stack2_.Size() > 0) {
      stack2_.PushFront(stack1_.Back());
      stack1_.PopBack();
    }
    stack1_.PushBack(value);
  }
};
int main() {
  int n;
  std::cin >> n;
  char zapros;
  int64_t num;
  Goblin goblin;
  for (int i = 0; i < n; i++) {
    std::cin >> zapros;
    if (zapros == '+') {
      std::cin >> num;
      goblin.Enqueue(num);
    }
    if (zapros == '*') {
      std::cin >> num;
      goblin.Mid(num);
    }
    if (zapros == '-') {
      std::cout << goblin.Dequeue() << '\n';
    }
  }
  goblin.Clear();
  return 0;
}