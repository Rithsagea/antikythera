#include "base.hpp"

/*
isMatch :: string, pattern
  return helper(string, condense(pattern), 0, 0)

condense :: pattern
  res = ""
  loop through pattern
    if current pattern is wildcard
      if end of res is same wildcard
        skip
    append current char to res

helper function :: string, pattern, stringPos (sPos), patternPos (pPos)
  iterate :: pattern[patternPos, end]
    if next token is "*" (greedy)
      range :: sPos, string.size - 1
        if remaining tokens match, continue
        check if current character matches pattern
    else if pattern[pPos] doesn't match string[sPos], return false
    increment sPos and pPos
  return sPos == string.size (fully digested string)
*/

#define matchChar(c, p) (p == '.' || c == p)

class Solution {
  public:

  bool isMatch(string s, string p, int sPos, int pPos) {
    while (pPos < p.size()) {
      if (pPos + 1 < p.size() && p[pPos + 1] == '*') { // greedy
        while (sPos < s.size()) {
          if (isMatch(s, p, sPos, pPos + 2)) return true;
          if (sPos >= s.size() || !matchChar(s[sPos], p[pPos])) return false;
          sPos++;
        }
        pPos += 2;
        continue;
      }
      else if (sPos >= s.size() || !matchChar(s[sPos], p[pPos])) return false;
      sPos++, pPos++;
    }
    return sPos == s.size() && pPos == p.size();
  }

  string condense(string p) {
    string res = "";
    for (int i = 0; i < p.size(); i++) {
      if (i + 1 < p.size() && p[i + 1] == '*' && res.back() == '*') {
        if (res[res.size() - 2] == p[i]) {
          i++;
          continue;
        }
      }
      res += p[i];
    }
    return res;
  }

  bool isMatch(string s, string p) {
    return isMatch(s, condense(p), 0, 0);
  }
};