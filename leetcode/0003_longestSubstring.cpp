#include "base.hpp"

/*
iterate through entire string's characters
  if character has been seen
    remove characters from "start" until character is no longer seen
  add character to seen characters
  update longest substring length
*/

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    vector<bool> characters(numeric_limits<unsigned char>::max(), false);
    int start = 0, end = 0, longest = 0;
    for (end = 0; end < s.size(); end++) {
      while (characters[s[end]]) {
        characters[s[start]] = false;
        start++;
      }
      characters[s[end]] = true;
      longest = max(longest, end - start + 1);
    }

    return longest;
  }
};