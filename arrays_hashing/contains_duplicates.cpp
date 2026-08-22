/* Approach :

1. Create an unordered_set.
2. Traverse the array.
3. If the current element already exists in the set, return true.
4. Otherwise, insert it into the set.
5. If no duplicate is found after traversing the entire array, return false.

Time Complexity : O(n)
Space Complexity : O(n) */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;

        for(int num : nums){
            if(st.find(num) != st.end()){
                return true;
            }
            st.insert(num);
        }

        return false;
    }
};