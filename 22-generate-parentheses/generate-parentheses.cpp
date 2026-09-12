class Solution {
public:
    vector<string> ans;

    void fun(string s, int n, int open, int close) {

        if (open == n && close == n) {
            ans.push_back(s);
            return;
        }

        if (open < n) {
            s.push_back('(');
            fun(s, n, open + 1, close);
            s.pop_back();
        }

        if (close < open) {
            s.push_back(')');
            fun(s, n, open, close + 1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        fun("", n, 0, 0);
        return ans;
    }
};