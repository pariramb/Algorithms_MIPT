#include <iostream>

#define MAX_COINS 15
#define RANGE_OF_DENOM 30
#define NOT_ENOUGH_COINS -1
#define CHANGE 0

void DontTake(int index_in_all_coins, int& count_coins_in_seq, int* all_coins, int* possible_sequence, int* sequence,
              uint64_t sum, int how_many_coins, int possible_count_coins_in_seq, uint64_t n);
void TakeOne(int index_in_all_coins, int& count_coins_in_seq, int* all_coins, int* possible_sequence, int* sequence,
             uint64_t sum, int how_many_coins, int possible_count_coins_in_seq, uint64_t n);
void TakeTwo(int index_in_all_coins, int& count_coins_in_seq, int* all_coins, int* possible_sequence, int* sequence,
             uint64_t sum, int how_many_coins, int possible_count_coins_in_seq, uint64_t n);

void DontTake(int index_in_all_coins, int& count_coins_in_seq, int* all_coins, int* possible_sequence, int* sequence,
              uint64_t sum, int how_many_coins, int possible_count_coins_in_seq, uint64_t n) {
  if (index_in_all_coins > how_many_coins - 2) {
    return;
  }
  DontTake(index_in_all_coins + 1, count_coins_in_seq, all_coins, possible_sequence, sequence, sum, how_many_coins,
           possible_count_coins_in_seq,
           n);  //не берём
  TakeOne(index_in_all_coins + 1, count_coins_in_seq, all_coins, possible_sequence, sequence, sum, how_many_coins,
          possible_count_coins_in_seq,
          n);  //берём
  TakeTwo(index_in_all_coins + 1, count_coins_in_seq, all_coins, possible_sequence, sequence, sum, how_many_coins,
          possible_count_coins_in_seq, n);  //берём 2
}
void TakeOne(int index_in_all_coins, int& count_coins_in_seq, int* all_coins, int* possible_sequence, int* sequence,
             uint64_t sum, int how_many_coins, int possible_count_coins_in_seq, uint64_t n) {
  possible_sequence[possible_count_coins_in_seq] = all_coins[index_in_all_coins];  //поменять типы
  sum = sum + possible_sequence[possible_count_coins_in_seq];
  possible_count_coins_in_seq += 1;
  if ((sum == n) && (count_coins_in_seq > possible_count_coins_in_seq)) {
    int i = 0;
    while (i < possible_count_coins_in_seq) {
      sequence[i] = possible_sequence[i];
      ++i;
    }
    count_coins_in_seq = possible_count_coins_in_seq;
    return;
  }
  if ((index_in_all_coins > how_many_coins - 2) | (sum > n)) {
    return;
  }
  DontTake(index_in_all_coins + 1, count_coins_in_seq, all_coins, possible_sequence, sequence, sum, how_many_coins,
           possible_count_coins_in_seq,
           n);  //не берём
  TakeOne(index_in_all_coins + 1, count_coins_in_seq, all_coins, possible_sequence, sequence, sum, how_many_coins,
          possible_count_coins_in_seq,
          n);  //берём
  TakeTwo(index_in_all_coins + 1, count_coins_in_seq, all_coins, possible_sequence, sequence, sum, how_many_coins,
          possible_count_coins_in_seq, n);
}
void TakeTwo(int index_in_all_coins, int& count_coins_in_seq, int* all_coins, int* possible_sequence, int* sequence,
             uint64_t sum, int how_many_coins, int possible_count_coins_in_seq, uint64_t n) {
  possible_sequence[possible_count_coins_in_seq] = all_coins[index_in_all_coins];  //поменять типы
  possible_sequence[possible_count_coins_in_seq + 1] = all_coins[index_in_all_coins];
  sum = sum + possible_sequence[possible_count_coins_in_seq] * 2;
  possible_count_coins_in_seq += 2;
  if ((sum == n) && (count_coins_in_seq > possible_count_coins_in_seq)) {
    int i = 0;
    while (i < possible_count_coins_in_seq) {
      sequence[i] = possible_sequence[i];
      ++i;
    }
    count_coins_in_seq = possible_count_coins_in_seq;
    return;
  }
  if ((index_in_all_coins > how_many_coins - 2) | (sum > n)) {
    return;
  }
  DontTake(index_in_all_coins + 1, count_coins_in_seq, all_coins, possible_sequence, sequence, sum, how_many_coins,
           possible_count_coins_in_seq,
           n);  //не берём
  TakeOne(index_in_all_coins + 1, count_coins_in_seq, all_coins, possible_sequence, sequence, sum, how_many_coins,
          possible_count_coins_in_seq,
          n);  //берём
  TakeTwo(index_in_all_coins + 1, count_coins_in_seq, all_coins, possible_sequence, sequence, sum, how_many_coins,
          possible_count_coins_in_seq, n);
}
int main() {
  int n, m;
  int all_coins[MAX_COINS];
  int64_t sum = 0;
  int count_coins_in_seq = RANGE_OF_DENOM + 1;
  std::cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    std::cin >> all_coins[i];
    sum += all_coins[i] * 2;
  }
  int possible_sequence[RANGE_OF_DENOM]{};
  int sequence[RANGE_OF_DENOM]{};
  if (sum < n) {
    std::cout << NOT_ENOUGH_COINS;
  } else {
    DontTake(0, count_coins_in_seq, all_coins, possible_sequence, sequence, 0, m, 0, n);
    TakeOne(0, count_coins_in_seq, all_coins, possible_sequence, sequence, 0, m, 0, n);
    TakeTwo(0, count_coins_in_seq, all_coins, possible_sequence, sequence, 0, m, 0, n);
    if (count_coins_in_seq != RANGE_OF_DENOM + 1) {
      std::cout << count_coins_in_seq << '\n';
      for (int i = 0; i < count_coins_in_seq; ++i) {
        std::cout << sequence[i] << ' ';
      }
    } else {
      std::cout << CHANGE;
    }
  }
  return 0;
}