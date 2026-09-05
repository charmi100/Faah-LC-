class Solution {
public:
    string convert(string s, int numRows) {

        // If only one row, zigzag is not possible
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        vector<string> rows(numRows);

        int row = 0;
        int direction = 1;   // 1 = down, -1 = up

        for (char ch : s) {

            // Put character in current row
            rows[row] += ch;

            // Change direction at top or bottom
            if (row == 0) {
                direction = 1;
            }
            else if (row == numRows - 1) {
                direction = -1;
            }

            row += direction;
        }

        // Combine all rows
        string ans;

        for (string r : rows) {
            ans += r;
        }

        return ans;
    }
};
