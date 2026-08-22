/*
Problem: Maximum Subarray Sum

My Approach:
- Try all subarrays → O(n^2 / O(n^3)).

Optimized Idea:
- If sum becomes negative → reset it.
- Keep tracking maximum sum.

Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum = 0, maxSum = nums[0];

        for(int num : nums) {

            sum += num;
            maxSum = max(maxSum, sum);

            if(sum < 0) sum = 0;
        }

        return maxSum;
    }
};