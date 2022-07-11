class Solution {
public:
    
    bool bfs(vector<vector<int>> &graph,vector<bool> visited, int S,int E){

        queue<int> q;
        q.push(S);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            visited[node] = true;
            if(node==E){
                return true;
            }
            for(int adj_node : graph[node]){
                if(!visited[adj_node])
                    q.push(adj_node);
            }
        }
        
        return false;
        
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> adj(n);
        for(vector<int> edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n);
        
        return bfs(adj,visited,source,destination);
    }
};