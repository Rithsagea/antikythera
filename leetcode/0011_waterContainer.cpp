#include "base.hpp"

class Solution {
public:
  int maxArea(vector<int>& height) {
    //disable i/o for optimization (not production)
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int a = 0, b = height.size() - 1, maxSize = 0, h;
    while (a < b) {
      h = min(height[a], height[b]);
      maxSize = max(maxSize, h * (b - a));
      while (height[a] <= h && a < b) a++;
      while (height[b] <= h && a < b) b--;
    }
    return maxSize;
  }
};