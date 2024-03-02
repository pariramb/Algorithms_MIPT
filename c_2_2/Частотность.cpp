#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

void MakeDict(std::map<std::string, int>& dict) {
  std::string str;
  while (std::cin >> str) {
    ++dict[str];  // если такого значения нет, то вставляет его(cpp.reference)
  }
}

std::vector<std::pair<std::string, int>> MakeVector(const std::map<std::string, int> dict) {
  auto it = dict.begin();
  auto comp = [](const std::pair<std::string, int>& word1, const std::pair<std::string, int>& word2) {
    if (word1.second != word2.second) {
      return (word1.second > word2.second);
    }
    return (word1.first < word2.first);
  };
  std::vector<std::pair<std::string, int>> sorted_dict;
  sorted_dict.reserve(dict.size());
  while (it != dict.end()) {
    sorted_dict.emplace_back(std::pair<std::string, int>(it->first, it->second));
    ++it;
  }
  std::sort(sorted_dict.begin(), sorted_dict.end(), comp);
  return sorted_dict;
}

int main() {
  std::map<std::string, int> words;
  MakeDict(words);
  auto vector = MakeVector(words);
  for (size_t i = 0; i < vector.size(); ++i) {
    std::cout << vector[i].first << '\n';
  }
  return 0;
}
