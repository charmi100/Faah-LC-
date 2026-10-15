class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (auto v : graph[node]) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[node];
                            q.push(v);
                        }
                        else if (color[v] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};