#include <iostream>

class AVL {
 public:
  struct Node {
    int64_t key;
    int64_t height = 1;
    Node* left = nullptr;
    Node* right = nullptr;
  };

 private:
  Node* root_ = nullptr;
  size_t size_ = 0;
  const Node* temp_ = nullptr;
  const Node* next_ = nullptr;
  Node* RemoveMin(Node* root);
  void Fixheight(Node* root);
  Node* RotateRight(Node* root);
  Node* RotateLeft(Node* root);
  Node* Balance(Node* root);
  Node* Add(AVL::Node* root, int64_t value);
  void Clear(Node* root);
  Node* RemoveMax(Node* root);
  AVL::Node* FindMin(Node* root) {
    return (root->left != nullptr ? FindMin(root->left) : root);
  }
  Node* FindMax(Node* root) {
    return (root->right != nullptr ? FindMax(root->right) : root);
  }

 public:
  size_t Size() {
    return size_;
  }
  int64_t RemoveMin();
  int64_t RemoveMax();
  int64_t FindMin() {
    return FindMin(root_)->key;
  }
  int64_t FindMax() {
    return FindMax(root_)->key;
  }
  size_t Height(const Node* node) {
    if (node == nullptr) {
      return 0;
    }
    return node->height;
  }
  int64_t Bfactor(const Node* root) {
    return Height(root->right) - Height(root->left);
  }
  const Node* Root() const {
    return root_;
  }
  const Node* Next() {
    temp_ = next_;
    next_ = nullptr;
    return temp_;
  }
  const Node* Find(const Node* root, int64_t value);
  const Node* Add(int64_t value);
  void Clear();
};

const AVL::Node* AVL::Find(const AVL::Node* root, int64_t value) {
  if (root == nullptr) {
    return nullptr;
  }
  if (value < root->key) {
    next_ = root;
    return Find(root->left, value);
  }
  if (value > root->key) {
    return Find(root->right, value);
  }
  if (value == root->key) {
    next_ = root;
    return root;
  }
  return nullptr;
}
void AVL::Fixheight(Node* root) {
  size_t height_left = AVL::Height(root->left);
  size_t height_right = AVL::Height(root->right);
  root->height = (height_left < height_right ? height_right : height_left) + 1;
}
AVL::Node* AVL::RotateRight(Node* root) {
  Node* new_root = root->left;
  root->left = new_root->right;
  new_root->right = root;
  Fixheight(root);
  Fixheight(new_root);
  if (root_ == root) {
    root_ = new_root;
  }
  return new_root;
}
AVL::Node* AVL::RotateLeft(Node* root) {
  Node* new_root = root->right;
  root->right = new_root->left;
  new_root->left = root;
  Fixheight(root);
  Fixheight(new_root);
  if (root_ == root) {
    root_ = new_root;
  }
  return new_root;
}
AVL::Node* AVL::Balance(Node* root) {
  Fixheight(root);
  int b_factor = Bfactor(root);
  if (b_factor == 2) {
    if (Bfactor(root->right) < 0) {
      root->right = RotateRight(root->right);
    }
    return RotateLeft(root);
  }
  if (b_factor == -2) {
    if (Bfactor(root->left) > 0) {
      root->left = RotateLeft(root->left);
    }
    return RotateRight(root);
  }
  return root;
}
AVL::Node* AVL::Add(AVL::Node* root, int64_t value) {
  if (root == nullptr) {
    auto new_el = new Node;
    new_el->key = value;
    if (root == root_) {
      root_ = new_el;
    }
    return new_el;
  }
  if (value < root->key) {
    root->left = Add(root->left, value);
  } else {
    root->right = Add(root->right, value);
  }
  return Balance(root);
}
const AVL::Node* AVL::Add(int64_t value) {
  ++size_;
  return AVL::Add(root_, value);
}
void AVL::Clear(Node* root) {
  if (root != nullptr) {
    Clear(root->left);
    Clear(root->right);
    delete root;
  }
  root_ = nullptr;
}
void AVL::Clear() {
  size_ = 0;
  AVL::Clear(root_);
}
AVL::Node* AVL::RemoveMin(AVL::Node* root) {
  if (root->left == nullptr) {
    if (root == root_) {
      root_ = root->right;
    }
    return root->right;
  }
  root->left = RemoveMin(root->left);
  return Balance(root);
}
AVL::Node* AVL::RemoveMax(AVL::Node* root) {
  if (root->right == nullptr) {
    if (root == root_) {
      root_ = root->left;
    }
    return root->left;
  }
  root->right = RemoveMax(root->right);
  return Balance(root);
}
int64_t AVL::RemoveMin() {
  --size_;
  Node* min = FindMin(root_);
  int64_t min_key = min->key;
  RemoveMin(root_);
  delete min;
  return min_key;
}
int64_t AVL::RemoveMax() {
  --size_;
  Node* max = FindMax(root_);
  int64_t max_key = max->key;
  RemoveMax(root_);
  delete max;
  return max_key;
}

int main() {
  int m;
  std::cin >> m;
  enum { kMaxSize = 20 };
  char command[kMaxSize];
  int64_t new_element;
  AVL dec;
  for (int i = 0; i < m; ++i) {
    std::cin >> command;
    switch (command[0]) {
      case 'i':
        std::cin >> new_element;
        dec.Add(new_element);
        std::cout << "ok\n";
        break;
      case 'e':
        if (dec.Size() == 0) {
          std::cout << "error\n";
        } else {
          if (command[9] == 'i') {
            std::cout << dec.RemoveMin() << '\n';
          } else {
            std::cout << dec.RemoveMax() << '\n';
          }
        }
        break;
      case 'g':
        if (dec.Size() == 0) {
          std::cout << "error\n";
        } else {
          if (command[5] == 'i') {
            std::cout << dec.FindMin() << '\n';
          } else {
            std::cout << dec.FindMax() << '\n';
          }
        }
        break;
      case 'c':
        dec.Clear();
        std::cout << "ok\n";
        break;
      case 's':
        std::cout << dec.Size() << '\n';
    }
  }
  dec.Clear();
  return 0;
}