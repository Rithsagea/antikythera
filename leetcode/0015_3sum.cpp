#include "base.hpp"

// Naive Solution
// class Solution {
//   public:
//   vector<vector<int>> threeSum(vector<int>& nums) {
//     vector<vector<int>> result;

//     for (int i = 0; i < nums.size(); i++) {
//       for (int j = i + 1; j < nums.size(); j++) {
//         for (int k = j + 1; k < nums.size(); k++) {
//           if (nums[i] + nums[j] + nums[k] == 0) {
//             vector<int> v = { nums[i], nums[j], nums[k] };
//             sort(v.begin(), v.end());
//             if (find(result.begin(), result.end(), v) == result.end()) {
//               result.push_back(v);
//             }
//           }
//         }
//       }
//     }

//     return result;
//   }
// };

/*
range i[0, nums.length - 1]
  skip i if it is duplicate
  use 2 pointers j at i + 1, k at nums.length - 1
  while j and k do not pass
    check nums[i, j, k] sum to 0
    add to result if it does
    move j and k to next position (skip duplicates)
*/
class Solution {
  public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;

    int sum;
    for (int i = 0; i < nums.size(); i++) {
      if(i != 0 && nums[i] == nums[i - 1]) continue;

      int j = i + 1;
      int k = nums.size() - 1;

      while (j < k) {
        sum = nums[i] + nums[j] + nums[k];
        if (sum == 0) {
          result.push_back({ nums[i], nums[j], nums[k] });
          while(j < k && nums[j] == nums[j + 1]) j++;
          while(j < k && nums[k] == nums[k - 1]) k--;
          j++, k--;
        } else if (sum > 0) {
          k--;
        } else {
          j++;
        }
      }
    }

    return result;
  }
};