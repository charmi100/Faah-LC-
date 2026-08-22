/*
Problem: Remove Duplicates from Sorted Array

My Approach:
- Initially thought to use extra array/set.
- Then realized array is sorted → duplicates are adjacent.

Optimized Idea:
- Use two pointers.
- Keep track of last unique element.
- Overwrite duplicates in-place.

Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int i = 0;

        for(int j = 1; j < nums.size(); j++) {
            if(nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};