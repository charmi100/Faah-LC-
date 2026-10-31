
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }

        queue<pair<int,int>> q;
        q.push({0, 0});

        vector<vector<int>> visited(n, vector<int>(n, 0));
        visited[0][0] = 1;

        int steps = 1;

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto current = q.front();
                q.pop();

                int r = current.first;
                int c = current.second;

                if (r == n - 1 && c == n - 1) {
                    return steps;
                }

                for (int d = 0; d < 8; d++) {
                    int newRow = r + dr[d];
                    int newCol = c + dc[d];

                    if (newRow >= 0 && newRow < n &&
                        newCol >= 0 && newCol < n &&
                        grid[newRow][newCol] == 0 &&
                        visited[newRow][newCol] == 0) {

                        visited[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};
