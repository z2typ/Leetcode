class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = prerequisites.size();
        vector<int> inDegree(numCourses);
        
        vector<vector<int>> graph(numCourses);
        
        
        for(vector<int> edge : prerequisites){
            inDegree[edge[0]] += 1;
            graph[edge[1]].push_back(edge[0]);
        }
        
        queue<int> q;
        
        for(int i=0; i<numCourses; i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> visited(numCourses);
        vector<int> topoSort;
            
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                int node = q.front();
                q.pop();
                if(!visited[node])
                    topoSort.push_back(node);
                visited[node] = 1;
                for(int adj_node : graph[node]){
                    inDegree[adj_node] -= 1;
                    if(!visited[adj_node] && inDegree[adj_node]==0){
                        q.push(adj_node);
                    }
                }
                
            }
        }
        if(topoSort.size()<numCourses){
            return {};
        }
        return topoSort;
        
    }
};