class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> need;
        unordered_map<char, int> window;

        for(char c : t) {
            need[c]++;
        }

        int l = 0;
        int formed = 0;

        int minLen = INT_MAX;
        int start = 0;

        for(int right = 0; right < s.size(); right++) {

            window[s[right]]++;

            if(need.count(s[right]) &&
               window[s[right]] == need[s[right]]) {
                formed++;
            }

            while(formed == need.size()) {

                if(right - l + 1 < minLen) {
                    minLen = right - l + 1;
                    start = l;
                }

                window[s[l]]--;

                if(need.count(s[l]) &&
                   window[s[l]] < need[s[l]]) {
                    formed--;
                }

                l++;
            }
        }

        if(minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};