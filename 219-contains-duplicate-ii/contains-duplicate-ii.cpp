class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        for(int i = 0 ; i < nums.size() ; i++){
            int current = nums[i];
            mp.count(current);
            if (mp.count(current)){
                int prevIndex = mp[current];
                if(i -prevIndex <=k){
                    return true;
                }
            }
                mp[current] = i;
        }
        return false;
    }
};