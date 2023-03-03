#include "base.hpp"

/*
rows = 2
1 (1)
2

offsets = 1, 2

rows = 3, n = 4
1 (1)
2 4
3

offsets = 1, 2, 4, 3
2 -> 4
6 -> 8

rows = 4, n = 6
1 (1)
2 6
3 5
4

offsets = 1, 2, 6, 3, 5, 4

res = new string size of s
n = (numRows - 1) * 2 (number of offsets)
add every nth char to res (start from 1)
range i from 2 to numRows
  add i and inverse i char to res
add every -1 + nth char to res (start from n - 1)

*/

class Solution {
public:

  void add(string* res, string& s, int pos) {
    if (pos <= s.size())
      (*res) += (s[pos - 1]);
  }

  string convert(string s, int numRows) {
    string res; res.reserve(s.size());
    int n = (numRows - 1) * 2;
    if (n == 0) return s;

    for (int i = 1; i <= numRows; i++) {
      for (int j = i; j <= s.size(); j += n) {
        add(&res, s, j);
        if(i != 1 && i != numRows)
          add(&res, s, j - i * 2 + n + 2);
      }
    }

    return res;
  }
};