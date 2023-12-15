#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int getLongestSubseq(const std::string &X, const std::string &Y) {
  int m = X.size();
  int n = Y.size();

  std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (X[i - 1] == Y[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  return dp[m][n];
}

int main() {
  std::string X = "ABCDE";
  std::string Y = "DCDA";

  int result = getLongestSubseq(X, Y);
  std::cout << result << std::endl;

  return 0;
}
