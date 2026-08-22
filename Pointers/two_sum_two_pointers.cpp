/*
Problem: Two Sum II - Input Array is Sorted

Optimized Approach:
- Use two pointers (left and right)
- Because array is sorted:
    if sum > target → move right pointer left
    if sum < target → move left pointer right

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int n = numbers.size();
        int left = 0;
        int right = n - 1;

        while(left < right) {

            int sum = numbers[left] + numbers[right];

            if(sum == target) {
                return {left + 1, right + 1};
            }
            else if(sum < target) {
                left++;
            }
            else {
                right--;
            }
        }

        return {};
    }
};