class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mp;
        int count = 0;
        for(int i = 0 ; i < nums1.size() ; i++){
            for(int j = 0 ; j <nums2.size() ; j++){
                int sum = nums1[i] + nums2[j];
                mp[sum]++;
            }
        }
        for(int k = 0 ; k < nums3.size(); k++){
            for(int l = 0 ; l < nums4.size() ; l++){
                int currentSum = nums3[k] + nums4[l];
                int needed = -currentSum;
                if(mp.count(needed)){
                    count += mp[needed];
                }
            }
        }
        return count;
    }
};