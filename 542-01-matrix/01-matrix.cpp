
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int,int>> q;

        // Step 1: Scan entire matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Step 2: Directions
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Step 3: BFS
        while (!q.empty()) {

            auto current = q.front();
            q.pop();

            int r = current.first;
            int c = current.second;

            for (int d = 0; d < 4; d++) {

                int newRow = r + dr[d];
                int newCol = c + dc[d];

                if (newRow >= 0 && newRow < m &&
                    newCol >= 0 && newCol < n &&
                    dist[newRow][newCol] == -1) {

                    dist[newRow][newCol] = dist[r][c] + 1;
                    q.push({newRow, newCol});
                }
            }
        }

        return dist;
    }
};
