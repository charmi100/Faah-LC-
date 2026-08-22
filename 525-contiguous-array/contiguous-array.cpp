class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int , int>mp;

        int prefix = 0;
        int maxLength = 0;

        mp[0] = -1;

        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0){
                prefix += -1;
            }
            if(nums[i] == 1){
                prefix += 1;
            }
            if(mp.count(prefix)){
              int length = i - mp[prefix];
              maxLength = max(maxLength , length);
            }
            else{
                mp[prefix] = i;
            }
        }
        return maxLength;
    }
};