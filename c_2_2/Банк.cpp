#include <iostream>
#include <string>
#include <unordered_map>

void Request1(std::unordered_map<std::string, int>& dict) {
  std::string str;
  int money;
  std::cin >> str;
  std::cin >> money;
  dict[str] += money;
}

void Request2(std::unordered_map<std::string, int>& dict) {
  std::string str;
  std::cin >> str;
  auto it_key = dict.find(str);
  if (it_key != dict.end()) {
    std::cout << it_key->second << '\n';
  } else {
    std::cout << "ERROR\n";
  }
}

void Result(std::unordered_map<std::string, int>& dict, const size_t commands) {
  int command;
  for (size_t i = 0; i < commands; ++i) {
    std::cin >> command;
    if (command == 1) {
      Request1(dict);
    } else {
      Request2(dict);
    }
  }
}

int main() {
  std::unordered_map<std::string, int> bank;
  size_t commands;
  std::cin >> commands;
  Result(bank, commands);
  return 0;
}
