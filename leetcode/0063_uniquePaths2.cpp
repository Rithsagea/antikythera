#include "base.hpp"

/*
variation on 0062_uniquePaths.cpp

calculate edges first, stopping at first obstacle
only calculate a grid cell if no obstacle, else it is 0
*/

class Solution {
  public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int length = obstacleGrid.size();
    int width = obstacleGrid[0].size();
    vector<vector<int>> dp(length, vector<int>(width));

    for (int i = 0; i < length && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
    for (int i = 0; i < width && obstacleGrid[0][i] == 0; i++) dp[0][i] = 1;

    for (int i = 1; i < length; i++) {
      for (int j = 1; j < width; j++) {
        if (obstacleGrid[i][j] == 0)
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }

    return dp[length - 1][width - 1];
  }
};