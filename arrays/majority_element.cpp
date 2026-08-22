/*
Problem: Majority Element

My Approach:
- Count frequency of each element → O(n^2 or O(n log n)).

Optimized Idea:
- Use Moore’s Voting Algorithm.
- Cancel out different elements.

Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int count = 0, candidate = 0;

        for(int num : nums) {
            if(count == 0) candidate = num;

            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};