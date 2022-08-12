class Solution {
public:
    const int INF = INT_MAX;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n,INF);
        
        dist[k-1] = 0;
        
        for(int i=0;i<n-1;i++){
            for(vector<int> edge : times){
                if(dist[edge[0]-1]!=INF){
                    dist[edge[1]-1] = min(dist[edge[1]-1],dist[edge[0]-1]+edge[2]);
                }
            }
        }
        
        int max_time = *max_element(dist.begin(),dist.end());
        
        if(max_time==INF){
            return -1;
        }
        return max_time;
        
        
    }
};