class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int currentPrefix = 0;
        int count = 0;
        mp[0] = 1;
        for(int i = 0 ; i < nums.size() ; i++){
            currentPrefix += nums[i];
            int neededPrefix = currentPrefix - k;

            if (mp.count(neededPrefix)) {
                count += mp[neededPrefix];
            }
            mp[currentPrefix]++;
                }
                return count;
    }
};