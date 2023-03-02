#include "base.hpp"

// https://leetcode.com/problems/two-sum/description/

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> diffMap;

    for (int i = 0; i < nums.size(); i++) {
      if (diffMap.find(nums[i]) != diffMap.end())
        diffMap[target - nums[i]] = i;
      else
        return { i, diffMap[nums[i]] };
    }

    return { -1, -1 }; // error
  }
};