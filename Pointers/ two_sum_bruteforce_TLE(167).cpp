/*
Problem: Two Sum II - Input Array is Sorted

Approach:
- considering index 1 as i and index 2 as j
- we can use two nested loops to iterate through the array and check if the sum of numbers at index i and j equals the target
- Check if sum equals target

Why it is not optimal:
- Time complexity is O(n^2)
- Gives Time Limit Exceeded for large inputs

But it helps in understanding the problem.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {

                if(numbers[i] + numbers[j] == target) {
                    return {i + 1, j + 1};
                }
            }
        }

        return {};
    }
};