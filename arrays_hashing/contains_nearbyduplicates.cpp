/* Approach :

1. Traverse the array using two nested loops.
2. Compare every pair of elements.
3. If two elements are equal and the distance between their indices is less than or equal to k, return true.
4. If no such pair exists, return false.

Time Complexity : O(n²)
Space Complexity : O(1) */

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

O(n²)

Space Complexity

O(1)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        int n = nums.size();

        for(int i = 0; i < n; i++){

            for(int j = i + 1; j < n; j++){

                if(nums[i] == nums[j] && abs(i - j) <= k){
                    return true;
                }

            }
        }

        return false;
    }
};