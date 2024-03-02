#include <algorithm>
#include <iostream>

#define MAX_COUNT 100'000

struct OneCard {
  int score;
  int count;
};
int main() {
  int n, k;
  std::cin >> n >> k;
  auto all_cards = new OneCard*[n];
  int all_cards_arr[MAX_COUNT];
  //
  for (int i = 0; i < n; ++i) {
    std::cin >> all_cards_arr[i];
  }
  //заполнение и подсчёт одинаковых комбинаций
  std::sort(all_cards_arr, all_cards_arr + n);
  int64_t size = 0;
  int64_t all_combinations = 0;
  for (int i = 0; i < n;) {
    all_cards[size] = new OneCard;
    all_cards[size]->score = all_cards_arr[i];
    int counter = 0;
    while ((i + counter < n) && (all_cards_arr[i] == all_cards_arr[i + counter])) {
      ++counter;
    }
    all_cards[size++]->count = counter;
    if (counter > 2) {
      ++all_combinations;
    }
    i += counter;
  }
  int64_t j = 1;
  int64_t len = 1;
  for (int64_t i = 0; i < size; ++i) {
    while (j < size && static_cast<double>(all_cards[j]->score) / static_cast<double>(all_cards[i]->score) <= k) {
      all_combinations += 6 * len * (len - 1) / 2;
      if (all_cards[j++]->count > 1) {
        all_combinations += 3 * len;
      }
      ++len;
    }
    if (all_cards[i]->count > 1) {
      all_combinations += 3 * (len - 1);
    }
    --len;
  }

  std::cout << all_combinations;
  //удаление
  for (int64_t i = 0; i < size; ++i) {
    delete all_cards[i];
  }
  delete[] all_cards;
  return 0;
}