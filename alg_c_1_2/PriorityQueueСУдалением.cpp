#include <iostream>

class BinaryHeap {
  int* queue_;
  size_t size_ = 0;
  size_t index_ = 0;
  size_t one_more_index_ = 0;

 public:
  explicit BinaryHeap(int max_size) {
    queue_ = new int[max_size];
  }

  template <class T>
  T* Parent(T* child, T* begin) {
    if (begin < child) {
      return begin + ((child - begin) - 1) / 2;
    }
    return nullptr;
  }

  template <class T>
  T* LeftChild(T* parent, T* end, T* begin) {
    T* left_child = parent + (parent - begin) + 1;
    if (left_child < end) {
      return left_child;
    }
    return nullptr;
  }

  template <class T>
  T* RightChild(T* parent, T* end, T* begin) {
    T* right_child = parent + (parent - begin) + 2;
    if (right_child < end) {
      return right_child;
    }
    return nullptr;
  }

  template <class T>
  size_t SiftDown(T* begin, T* end, T* wrong_el) {
    T* left = LeftChild(wrong_el, end, begin);
    T* right = RightChild(wrong_el, end, begin);
    T* largest = wrong_el;
    one_more_index_ = largest - begin + 1;
    if ((left != nullptr) && (*largest < *left)) {
      largest = left;
    }
    if ((right != nullptr) && (*largest < *right)) {
      largest = right;
    }
    if (largest != wrong_el) {
      std::swap(*largest, *wrong_el);
      one_more_index_ = largest - begin + 1;
      return SiftDown(begin, end, largest);
    }
    return one_more_index_;
  }

  template <class T>
  size_t SiftUp(T* begin, T* end, T* wrong_el) {
    T* parent = Parent(wrong_el, begin);
    index_ = wrong_el - begin + 1;
    if ((parent != nullptr) && (*parent < *wrong_el)) {
      std::swap(*parent, *wrong_el);
      index_ = parent - begin + 1;
      return SiftUp(begin, end, parent);
    }
    return index_;
  }

  int MaxElement() {
    return queue_[0];
  }

  size_t AddElement(int parameter) {
    queue_[size_] = parameter;
    ++size_;
    return SiftUp(queue_, queue_ + size_, queue_ + size_ - 1);
  }

  int DeleteElement(int index) {
    std::swap(queue_[index], queue_[size_ - 1]);
    --size_;
    SiftUp(queue_, queue_ + size_, queue_ + index);
    SiftDown(queue_, queue_ + size_, queue_ + index);
    return queue_[size_];
  }
  size_t DelMax() {
    index_ = 0;
    if (size_ == 1) {
      --size_;
      return index_;
    }
    if (size_ != 0) {
      std::swap(queue_[0], queue_[size_ - 1]);
      --size_;
      return SiftDown(queue_, queue_ + size_, queue_);
    }
    return index_;
  }

  size_t Size() const {
    return size_;
  }

  const int* Queue() const {
    return queue_;
  }

  void DelQueue() {
    delete[] queue_;
  }
};

int main() {
  size_t max_size;
  int m;
  std::cin >> max_size >> m;
  BinaryHeap heap(max_size);
  int type;
  int parameter;
  size_t index;

  for (int i = 0; i < m; ++i) {
    std::cin >> type;
    if (type == 1) {
      if (heap.Size() == 0) {
        std::cout << -1 << "\n";
      } else {
        int max_el = heap.MaxElement();
        std::cout << heap.DelMax() << ' ' << max_el << "\n";
      }
      continue;
    }
    if (type == 2) {
      std::cin >> parameter;
      if (heap.Size() == max_size) {
        std::cout << -1 << '\n';
      } else {
        std::cout << heap.AddElement(parameter) << '\n';
      }
      continue;
    }
    if (type == 3) {
      std::cin >> index;
      if ((index > heap.Size()) || (index == 0)) {
        std::cout << -1 << '\n';
      } else {
        std::cout << heap.DeleteElement(index - 1) << '\n';
      }
      continue;
    }
  }
  const int* queue = heap.Queue();
  size_t size = heap.Size();
  for (size_t i = 0; i < size; ++i) {
    std::cout << queue[i] << ' ';
  }
  heap.DelQueue();
  return 0;
}