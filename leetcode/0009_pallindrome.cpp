#include "base.hpp"

/*
base case: negative, or ends in 0
reverse half then compare
*/

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0 || (x != 0 && x % 10 == 0)) return false;
    int res = 0;
    while (x > res) {
      res = res * 10 + x % 10;
      x /= 10;
    }
    return res == x || res / 10 == x;
  }
};
