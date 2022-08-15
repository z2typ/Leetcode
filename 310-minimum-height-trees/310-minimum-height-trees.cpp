class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        vector<int> degree(n);
        
        vector<vector<int>> graph(n);
        
        
        for(vector<int> edge : edges){
            degree[edge[0]]++;
            degree[edge[1]]++;
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        queue<int> q;
        
        for(int i=0;i<n;i++){
            if(degree[i]==1){
                q.push(i);
            }
        }
        vector<int> visited(n);
        while(n > 2){
            int size = q.size();
            n = n-size;
            for(int i=0;i<size;i++){
                int node = q.front();
                q.pop();
                visited[node] = 1;
                for(int adj_node : graph[node]){
                    degree[adj_node]--;
                    degree[node]--;

                    if(degree[adj_node]==1){
                        q.push(adj_node);
                    }
                    
                }
                
            }   
        }
        
        vector<int> ans;
        
        for(int i=0;i<visited.size();i++){
            if(visited[i]==0){
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
};