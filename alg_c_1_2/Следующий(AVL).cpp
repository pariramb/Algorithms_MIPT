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
  const Node* temp_ = nullptr;
  const Node* next_ = nullptr;
  void Fixheight(Node* root);
  Node* RotateRight(Node* root);
  Node* RotateLeft(Node* root);
  Node* Balance(Node* root);
  Node* Add(AVL::Node* root, int64_t value);
  void Clear(Node* root);

 public:
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
const AVL::Node* AVL::Find(const Node* root, int64_t value) {
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
  if (AVL::Find(root_, value) == nullptr) {
    Next();
    return AVL::Add(root_, value);
  }
  Next();
  return nullptr;
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
  AVL::Clear(root_);
}
int main() {
  AVL avl;
  enum { kQuestion = 63, kPlus = 43, kMaxEl = 1000000000 };
  size_t n;
  char sign;
  char prev_sign = 'a';
  int64_t parameter, prev_parameter;
  const AVL::Node* temp = nullptr;
  std::cin >> n;
  for (size_t i = 0; i < n; ++i) {
    std::cin >> sign;
    std::cin >> parameter;
    if (sign == kQuestion) {
      avl.Find(avl.Root(), parameter);
      temp = avl.Next();
      if (temp != nullptr) {
        std::cout << temp->key << '\n';
        prev_parameter = temp->key;
      } else {
        prev_parameter = -1;
        std::cout << -1 << '\n';
      }
    }
    if (sign == kPlus) {
      if (prev_sign == kQuestion) {
        avl.Add((prev_parameter + parameter) % kMaxEl);
      } else {
        avl.Add(parameter);
      }
    }
    prev_sign = sign;
  }
  avl.Clear();
  return 0;
}