#include <iostream>

class BST {
  struct Node {
    int64_t value;
    Node* parent;
    Node* left_child;
    Node* right_child;
  };
  size_t high_ = 0;
  size_t high_temp_ = 0;
  Node* root_ = nullptr;
  Node* Find(Node* root, int64_t value) {
    if ((root == nullptr) || (value == root->value)) {
      return root;
    }
    if (value > root->value) {
      return Find(root->right_child, value);
    }
    if (value < root->value) {
      return Find(root->left_child, value);
    }
    return nullptr;
  }
  void Insert(Node* root, Node* insert) {
    while (root != nullptr) {
      if (insert->value > root->value) {
        if (root->right_child != nullptr) {
          root = root->right_child;
          ++high_temp_;
        } else {
          insert->parent = root;
          root->right_child = insert;
          ++high_temp_;
          if (high_ < high_temp_) {
            high_ = high_temp_;
          }
          break;
        }
      } else {
        if (root->left_child != nullptr) {
          root = root->left_child;
          ++high_temp_;
        } else {
          insert->parent = root;
          root->left_child = insert;
          ++high_temp_;
          if (high_ < high_temp_) {
            high_ = high_temp_;
          }
          break;
        }
      }
    }
    if (root == nullptr) {
      root_ = insert;
      if (high_ < high_temp_) {
        high_ = high_temp_;
      }
    }
  }

  void Clear(Node* root) {
    if (High() != 0) {
      if (root->left_child != nullptr) {
        Clear(root->left_child);
      }
      if (root->right_child != nullptr) {
        Clear(root->right_child);
      }
      delete root;
    }
  }
  void Razvilki(Node* root) {
    if (root != nullptr) {
      Razvilki(root->left_child);
      if ((root->left_child != nullptr) && (root->right_child != nullptr)) {
        std::cout << root->value << '\n';
      }
      Razvilki(root->right_child);
    }
  }

 public:
  Node* Find(int64_t value) {
    return Find(root_, value);
  }
  void Insert(int64_t value) {
    auto node = new Node;
    node->value = value;
    node->parent = nullptr;
    node->left_child = nullptr;
    node->right_child = nullptr;
    high_temp_ = 1;
    Insert(root_, node);
  }
  void Clear() {
    Clear(root_);
  }
  size_t High() {
    return high_;
  }
  void Razvilki() {
    Razvilki(root_);
  }
};

int main() {
  int64_t value;
  BST bst;
  while (std::cin >> value) {
    if (value == 0) {
      break;
    }
    if ((bst.High() == 0) || (bst.Find(value) == nullptr)) {
      bst.Insert(value);
    }
  }
  if (bst.High() != 0) {
    bst.Razvilki();
  }
  bst.Clear();
  return 0;
}