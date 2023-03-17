#include "base.hpp"

/*
iterate through string
  value := current char symbol to int
  if part is 0 or value does not subtract into part
    increment res by part
    set part to value
  else
    increment res by value - part
    set part to 0
return res;
*/

class Solution {
  public:
  int getValue(char c) {
    switch(c) {
      case 'I': return 1;
      case 'V': return 5;
      case 'X': return 10;
      case 'L': return 50;
      case 'C': return 100;
      case 'D': return 500;
      case 'M': return 1000;
      default: return 0;
    }
  }

  int romanToInt(string s) {
    int res = 0, part = 0, value;
    for (auto& ch : s) {
      value = getValue(ch);
      if (part == 0 || part >= value) {
        res += part;
        part = value;
      } else {
        res += value - part;
        part = 0;
      }
    }

    return res + part;
  }
};