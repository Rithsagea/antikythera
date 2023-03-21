#include "base.hpp"

class Solution {
  public:
  string longestCommonPrefix(vector<string>& strs) {
    int pos = 0;

    while (true) {
      for (auto it = strs.begin()++; it != strs.end(); it++) {
        if (pos >= it->size() || (*it)[pos] != strs[0][pos]) {
          return strs[0].substr(0, pos);
        }
      }
      pos++;
    }
  }
};