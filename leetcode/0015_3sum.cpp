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

class Solution {
  public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    
  }
};