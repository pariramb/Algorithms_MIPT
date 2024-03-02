#include <algorithm>
#include <iostream>
#include <vector>

void MakeColors(std::vector<int>& all_animals, const size_t animals_count) {
  all_animals.reserve(animals_count);
  for (size_t i = 0; i < animals_count; ++i) {
    std::cin >> all_animals[i];
  }
}

void ReturnCommands(const std::vector<int>& all_animals) {
  size_t count_commands;
  std::cin >> count_commands;
  int command;
  for (size_t i = 0; i < count_commands; ++i) {
    std::cin >> command;
    std::cout << std::upper_bound(all_animals.cbegin(), all_animals.cend(), command) -
                     std::lower_bound(all_animals.cbegin(), all_animals.cend(), command)
              << '\n';
  }
}

int main() {
  size_t animals_count;
  std::cin >> animals_count;
  std::vector<int> all_animals(animals_count);
  MakeColors(all_animals, animals_count);
  ReturnCommands(all_animals);
  return 0;
}