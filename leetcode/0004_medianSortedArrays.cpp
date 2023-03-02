#include "base.hpp"

/*
median pos = totalSize of both arrays / 2
look from left to right for both arrays
increment smallest value
return value after median pos is 0 (?)
*/

// for another day
// https://leetcode.com/problems/median-of-two-sorted-arrays/solutions/2471/very-concise-o-log-min-m-n-iterative-solution-with-detailed-explanation/

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int totalSize = nums1.size() + nums2.size();
    auto it1 = nums1.begin(), it2 = nums2.begin();

    for (int i = totalSize / 2 - !(totalSize % 2); i > 0; i--) {
      if (it1 == nums1.end()) { advance(it2, i - 1); break; }
      if (it2 == nums2.end()) { advance(it1, i - 1); break; }
      if (*it1 < *it2) it1++;
      else it2++;
    }

    if (totalSize % 2 == 1) {
      if (it1 == nums1.end()) return *it2;
      if (it2 == nums2.end()) return *it1;
      return min(*it1, *it2);
    }

    if (it1 == nums1.end()) return (*it2 + *(++it2)) / 2.0;
    if (it2 == nums2.end()) return (*it1 + *(++it1)) / 2.0;

    int a, b;
    if (*it1 < *it2) {
      a = *(it1++);
      b = it1 == nums1.end() ? *it2 : min(*it1, *it2);
    } else {
      a = *(it2++);
      b = it2 == nums2.end() ? *it1 : min(*it1, *it2);
    }
    return (a + b) / 2.0;
  }
};