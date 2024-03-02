#include <iostream>
#include <string>
#include <unordered_map>

void MakeMap(std::unordered_map<std::string, std::string>& dict, const size_t count) {
  std::string str1;
  std::string str2;
  for (size_t i = 0; i < count; ++i) {
    std::cin >> str1;
    std::cin >> str2;
    dict.emplace(str1, str2);
    dict.emplace(str2, str1);
  }
}

void Result(std::unordered_map<std::string, std::string>& dict, const size_t count) {
  std::string str;
  for (size_t i = 0; i < count; ++i) {
    std::cin >> str;
    std::cout << dict[str] << '\n';
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::unordered_map<std::string, std::string> dict;
  size_t count_words;
  std::cin >> count_words;
  MakeMap(dict, count_words);
  size_t commands_count;
  std::cin >> commands_count;
  Result(dict, commands_count);
  return 0;
}
