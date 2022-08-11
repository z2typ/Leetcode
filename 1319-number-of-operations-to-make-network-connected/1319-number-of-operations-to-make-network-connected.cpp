class Solution {
public:
    vector<int> visited;
    void dfs(vector<vector<int>> &graph, int s){
        visited[s] = 1;
        for(int adj_node : graph[s]){
            if(!visited[adj_node]){
                dfs(graph, adj_node);
            }
        }
        
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if(edges < (n-1)){
            return -1;
        }
        
        visited = vector<int>(n);
        
        vector<vector<int>> adj(n);
        for(vector<int> conn : connections){
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(adj,i);
            }
        }
        
        return count-1;
        
    }
};