class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;

        // Step 1: Scan the entire grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        // Step 2: Handle the no-fresh-oranges case
        if(fresh == 0){
            return 0;
        }

        // Step 3: Declare minutes and directions
        int minutes = 0;

        int dr[] = { -1 , 1, 0 , 0};
        int dc[] = { 0 , 0 , -1 , 1};

        // Step 4: BFS loop
        while (!q.empty() && fresh > 0) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto current = q.front();
                q.pop();

                int r = current.first;
                int c = current.second;
                // Check its four neighbors
                for (int d = 0; d < 4; d++) {
                    int newRow = r + dr[d];
                    int newCol = c + dc[d];

                 if (newRow >= 0 && newRow < m &&
                        newCol >= 0 && newCol < n) {
                             if (grid[newRow][newCol] == 1) {
                            grid[newRow][newCol] = 2;
                            fresh--;

                            q.push({newRow, newCol});
                             }

                // If a neighbor is fresh, rot it,
                // push it into q, and decrement fresh
            }
                }
            }

            minutes++;
        }

        return (fresh == 0) ? minutes : -1;
    }
};