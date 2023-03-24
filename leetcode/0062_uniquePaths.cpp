#include "base.hpp"

/*
each cell in the dp is the total number of paths to that cell
calculate this incrementally from left to right, top to bottom
all edge cells filled with 1 pre-emptively (only 1 path to get there)
*/

class Solution {
  public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }

    return dp[m - 1][n - 1];
  }
};