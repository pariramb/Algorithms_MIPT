#include <algorithm>
#include <iostream>
#include <vector>

struct Result {
  size_t team_number;
  size_t count_tasks;
  size_t time;
};

void MakeResults(std::vector<Result>& commands, const size_t n) {
  commands.resize(n + 1);
  for (size_t i = 1; i < n + 1; ++i) {
    std::cin >> commands[i].count_tasks;
    std::cin >> commands[i].time;
    commands[i].team_number = i;
  }
}

bool Compare(const Result& result1, const Result& result2) {
  if (result1.count_tasks != result2.count_tasks) {
    return (result1.count_tasks > result2.count_tasks);
  }
  if (result1.time != result2.time) {
    return (result1.time < result2.time);
  }
  return (result1.team_number < result2.team_number);
}

int main() {
  size_t n;
  std::cin >> n;
  std::vector<Result> commands;
  MakeResults(commands, n);
  std::sort(commands.begin() + 1, commands.end(), Compare);
  for (size_t i = 1; i < n + 1; ++i) {
    std::cout << commands[i].team_number << '\n';
  }

  return 0;
}