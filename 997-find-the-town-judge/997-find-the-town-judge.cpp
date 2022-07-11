class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> outEdges(n,0);
        vector<int> inEdges(n,0);
        
        for(vector<int> edge : trust){
            outEdges[edge[0]-1]++;
            inEdges[edge[1]-1]++;
        }
        
        int judge = -1;
        for(int i=0;i<n;i++){
            if(outEdges[i]==0 && inEdges[i]==n-1){
                judge = i+1;
            }
        }
        
        return judge;
        
    }
};