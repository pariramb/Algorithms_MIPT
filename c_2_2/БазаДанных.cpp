#include <iostream>
#include <map>
#include <string>

struct CompareNames {
  bool operator()(const std::string& word1, const std::string& word2) const {
    return (word1 < word2);
  }
};

void MakeDict(std::map<std::string, std::map<std::string, size_t, CompareNames>, CompareNames>& dict) {
  std::string str;
  std::string str1;
  size_t count;
  while (std::cin >> str) {
    std::cin >> str1;
    std::cin >> count;
    dict[str][str1] += count;  //  то же самое, что в предыдущей задаче
  }
}

int main() {
  std::map<std::string, std::map<std::string, size_t, CompareNames>, CompareNames> dict;
  MakeDict(dict);
  for (auto it = dict.begin(); it != dict.end(); ++it) {
    std::cout << it->first << ":\n";
    for (auto it_items = it->second.begin(); it_items != it->second.end(); ++it_items) {
      std::cout << it_items->first << " " << it_items->second << '\n';
    }
  }
  return 0;
}
