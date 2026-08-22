/*
Problem: 3Sum

My Approach:
- First thought: 3 loops → O(n^3) (TLE expected).
- Then learned pattern: fix one number + solve 2Sum.

Optimized Idea:
- Sort array.
- Fix i.
- Use two pointers for remaining sum.
- Skip duplicates.

Time: O(n^2)
Space: O(1)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int n = nums.size();

        for(int i = 0; i < n; i++) {

            if(i > 0 && nums[i] == nums[i-1]) continue;

            int j = i + 1, k = n - 1;

            while(j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                if(sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++; k--;

                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
                else if(sum < 0) j++;
                else k--;
            }
        }

        return ans;
    }
};