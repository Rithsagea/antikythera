#include "base.hpp"

/*
follow algorithm as described
https://leetcode.com/problems/string-to-integer-atoi/
*/

class Solution {
public:
  int myAtoi(string s) {
    auto it = s.begin();
    while (it != s.end() && *it == ' ') it++;

    bool negative = false;
    if(*it == '+') it++;
    else if(*it == '-') negative = true, it++; 

    unsigned long res = 0;

    while (*it >= '0' && *it <= '9' && it != s.end()) {
      res = res * 10 + *it - '0';
      if(res > INT_MAX) return negative ? INT_MIN : INT_MAX;
      it++;
    }

    return negative ? -res : res;
  }
};