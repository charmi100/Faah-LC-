/*
Problem: Move Zeroes

My Initial Approach:
- I thought of storing all zeroes separately and moving non-zero elements
  to the front, then placing the zeroes at the end.
- This works but uses extra space.

Optimized Approach:
- Use two pointers.
- j keeps track of where the next non-zero element should be placed.
- Traverse the array with i.
- Whenever nums[i] is non-zero, place it at nums[j] and increment j.
- Fill remaining positions with 0.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
        }

        while(j < nums.size()) {
            nums[j] = 0;
            j++;
        }
    }
};