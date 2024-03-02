#include <iostream>
#include <queue>
#include <vector>

void MakeQueue(std::priority_queue<int, std::vector<int>, std::greater<int>>& sum_numbers) {
  size_t count;
  std::cin >> count;
  int number;
  for (size_t i = 0; i < count; ++i) {
    std::cin >> number;
    sum_numbers.push(number);
  }
}

double CountCoins(std::priority_queue<int, std::vector<int>, std::greater<int>>& sum_numbers) {
  double sum = 0;
  const double procents = 0.05;
  while (sum_numbers.size() != 1) {
    int first = sum_numbers.top();
    sum_numbers.pop();
    int second = sum_numbers.top();
    sum_numbers.pop();
    sum += (static_cast<double>(first + second) * procents);
    sum_numbers.push(first + second);
  }
  return sum;
}

int main() {
  std::priority_queue<int, std::vector<int>, std::greater<int>> sum_numbers;
  MakeQueue(sum_numbers);
  std::cout << CountCoins(sum_numbers);
  return 0;
}
