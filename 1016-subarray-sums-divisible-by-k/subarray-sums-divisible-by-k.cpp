class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int , int >mp;
        int currentPrefix = 0;
        int count = 0;
        mp[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            currentPrefix += nums[i];
            int remainder = (currentPrefix % k + k) % k;

            if(mp.count(remainder)){
                count += mp[remainder];
            }
            mp[remainder]++;
            }
        return count;
    }
};