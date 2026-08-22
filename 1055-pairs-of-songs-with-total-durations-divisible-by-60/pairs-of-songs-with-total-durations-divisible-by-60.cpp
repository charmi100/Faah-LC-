class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int , int>mp;
        int count = 0;

        for(int i = 0 ; i < time.size() ; i++){
            int remainder = time[i] % 60;
            int needed = (60 - remainder) % 60;

            if (mp.count(needed)){
                count += mp[needed];
            }
            mp[remainder]++;
        }
        return count;
    }
};