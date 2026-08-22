/* Approach :

1. Check if both strings have the same length. If not, return false.
2. Create an unordered_map<char, int> to store character frequencies.
3. Traverse the first string and increment the frequency of each character.
4. Traverse the second string and decrement the frequency of each character.
5. Traverse the map. If any frequency is not 0, return false.
6. Otherwise, return true.

Time Complexity : O(n)
Space Complexity :O(1) (fixed alphabet) / O(k) (general case) */

class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size())
            return false;

        unordered_map<char,int> mp;

        for(char ch : s){
            mp[ch]++;
        }

        for(char ch : t){
            mp[ch]--;
        }

        for(auto x : mp){
            if(x.second != 0){
                return false;
            }
        }

        return true;
    }
};