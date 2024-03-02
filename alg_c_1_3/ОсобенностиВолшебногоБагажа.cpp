#include <iostream>

void NumbersItems(size_t (*max_cost)[10001], size_t i, size_t j, size_t* weight) {
  if ((i > 0) && (j > 0)) {
    if (max_cost[i][j] != max_cost[i - 1][j]) {
      NumbersItems(max_cost, i - 1, j - weight[i], weight);
      std::cout << i << '\n';
    } else {
      NumbersItems(max_cost, i - 1, j, weight);
    }
  }
}

int main() {
  enum { kMaxItems = 101, kMaxWeight = 10001 };
  size_t cost[kMaxItems]{};
  size_t weight[kMaxItems]{};
  size_t max_cost[kMaxItems][kMaxWeight]{};
  size_t n, m;
  std::cin >> n >> m;
  for (size_t i = 1; i < n + 1; ++i) {
    std::cin >> weight[i];
  }
  for (size_t i = 1; i < n + 1; ++i) {
    std::cin >> cost[i];
  }
  for (size_t i = 1; i < n + 1; ++i) {
    for (size_t j = 1; j < m + 1; ++j) {
      if (weight[i] <= j) {
        max_cost[i][j] = std::max(max_cost[i - 1][j], max_cost[i - 1][j - weight[i]] + cost[i]);
      } else {
        max_cost[i][j] = max_cost[i - 1][j];
      }
    }
  }
  NumbersItems(max_cost, n, m, weight);
  return 0;
}