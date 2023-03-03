#include "base.hpp"

/*
literally just reverse atoi, but with overflow check
*/

class Solution {
public:
  int reverse(int x) {
    long long res = 0;
    int limit = INT_MAX / 10 + 1;

    while (x != 0) {
      if (abs(res) >= limit) return 0;
      res = res * 10 + x % 10;
      x /= 10;
    }

    return res;
  }
};