class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string , int> mp;
        vector<string> uniqueWords;
        vector<string> ans;

        for(string word : words){
            mp[word]++;
        }

        for (auto &it : mp) {
            uniqueWords.push_back(it.first);
            }
            sort(uniqueWords.begin(), uniqueWords.end(), [&](string a, string b) {

    if (mp[a] != mp[b]) {
        return mp[a] > mp[b];
    }

    return a < b;
});
for (int i = 0; i < k; i++) {
    ans.push_back(uniqueWords[i]);
}
return ans;
    }
};