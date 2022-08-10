class Solution {
public:
    
    unordered_set<int> uset;
    
    bool hasCycle(vector<vector<int>> &graph,vector<int> &visited,int start=0){
        int n = graph.size();
        uset.insert(start);
        visited[start] = 1;
        bool cycle = false;
        for(int node :graph[start]){
            if(uset.count(node)){
                return true;
            }
            if(!visited[node]){
                cycle = cycle || hasCycle(graph,visited,node);
            }
        }
        
        uset.erase(start);
        
        return cycle;    
        
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses,vector<int>());
        
        for(vector<int> preq : prerequisites){
            graph[preq[0]].push_back(preq[1]);
        }
        
        vector<int> visited(numCourses);
        
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(hasCycle(graph,visited,i)){
                    return false;
                }
            }
        }
        return true;
        
        

    }
};