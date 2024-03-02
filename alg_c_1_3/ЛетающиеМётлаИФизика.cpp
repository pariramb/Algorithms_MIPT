#include <iostream>

int main() {
  int m, n;
  enum { kWays = 16, kSigns = 51 };
  std::cin >> m >> n;
  int64_t dp[kWays][kSigns]{};
  dp[1][1] = 1;
  for (int i = 1; i < n + 1; ++i) {
    for (int j = 0; j < m + 1; ++j) {
      if (i < n) {
        dp[i + 1][j] += dp[i][j];
      }
      if ((i < n) && (j < m)) {
        dp[i + 1][j + 1] += dp[i][j];
      }
      if (j < m) {
        dp[i][j + 1] += dp[i][j];
      }
    }
  }
  std::cout << dp[n][m];
  return 0;
}