class Solution {
public:
    vector<int> topoSort;
    unordered_set<int> uset;
    int hasCycle = 0;
    void dfs(vector<vector<int>> &graph, int node,vector<int> & visited){
        visited[node] = 1;
        uset.insert(node);
        for(int adj_node : graph[node]){
            
            if(!visited[adj_node]){
                dfs(graph,adj_node,visited);
            }else if(uset.count(adj_node)){
                hasCycle = 1;
            }
        }
        topoSort.push_back(node);
        uset.erase(node);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> graph(numCourses);
        
        for(vector<int> edge : prerequisites){
            graph[edge[0]].push_back(edge[1]);
        }
        
        vector<int> visited(numCourses);
        for(int i=0;i<numCourses;i++){
            if(!visited[i])
                dfs(graph,i,visited);
        }
        if(hasCycle){
            topoSort.clear();
        }
        return topoSort;
        
    }
};