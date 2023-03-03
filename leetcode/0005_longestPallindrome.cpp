#include "base.hpp"

// https://leetcode.com/problems/longest-palindromic-substring/

/*
# Naive Solution

pair maxPair = 0, 0
loop a from 0 to string end
loop a from string end to a + maxPair.length
  loop b from a + maxPair.length to string end
    if a-b is pallindrome
      store a, b in maxPair

# 2 pointer solution

maxPair = a, a
iterate {a} from string start to end
  temp = expand(a, a)
  maxPair = max(maxPair, temp)
  temp = expand(a, a+1)
  maxPair = max(maxPair, temp)
return maxPair

expand(start, end)
  while(start == end)
    start--, end++
  return {start-1,end+1}
*/

class Solution {
public:
  pair<int, int> expand(string& s, int start, int end) {
    if (start < 0 || end > s.size() || s[start] != s[end]) return { 0, 0 };
    do { start--, end++; } while (start >= 0 && end < s.size() && s[start] == s[end]);
    return { start + 1, end - 1 };
  }

  pair<int, int> max(pair<int, int> a, pair<int, int> b) {
    return a.second - a.first > b.second - b.first ? a : b;
  }

  string longestPalindrome(string s) {
    pair<int, int> maxPair = { 0, 0 };
    for (int i = 0; i < s.size(); i++) {
      maxPair = max(maxPair, expand(s, i, i));
      maxPair = max(maxPair, expand(s, i, i + 1));
    }

    return s.substr(maxPair.first, maxPair.second - maxPair.first + 1);
  }
};