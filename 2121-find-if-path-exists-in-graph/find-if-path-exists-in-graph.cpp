class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
       vector<int> adj[n];
       
       for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
       }

       queue<int> q;
       vector<int> visited(n , 0);

       q.push(source);

       visited[source] = 1;

       while(!q.empty()){
        int node = q.front();
        q.pop();

       if(node == destination){
        return true;
       }
       for(auto neighbor : adj[node]){
        if(visited[neighbor] == 0){
            q.push(neighbor);
            visited[neighbor] = 1;
        }
       }
       }
        return false;
    }
};