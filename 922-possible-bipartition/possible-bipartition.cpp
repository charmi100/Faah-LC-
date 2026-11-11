class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<vector<int>> adj(n + 1);

        for (auto d : dislikes) {
            int u = d[0];
            int v = d[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n + 1, -1);

        for (int i = 1; i <= n; i++) {

            if (color[i] == -1) {

                queue<int> q;
                q.push(i);
                color[i] = 0;

                while (!q.empty()) {

                    int node = q.front();
                    q.pop();

                    for (int neighbor : adj[node]) {

                        if (color[neighbor] == -1) {
                            color[neighbor] = 1 - color[node];
                            q.push(neighbor);
                        }

                        else if (color[neighbor] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};