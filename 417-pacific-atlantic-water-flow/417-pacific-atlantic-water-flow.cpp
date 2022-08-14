class Solution {
public:
    vector<vector<bool>> visited;
    vector<vector<int>> grid;
    
    bool isSafe(vector<vector<int>> &heights, int x,int y,int currVal){
        int n = heights.size();
        int m = heights[0].size();
        return 0<=x && x<n && 0<=y && y<m && !visited[x][y] && heights[x][y]>=currVal;
    }
    
    int X[4] = {1,-1,0,0};
    int Y[4] = {0,0,1,-1};
    void dfs(vector<vector<int>> &heights,int x,int y,int value){
        
        visited[x][y] = true;
        grid[x][y] += value;
        for(int i=0;i<4;i++){
            if(isSafe(heights,x+X[i],y+Y[i],heights[x][y])){
                dfs(heights,x+X[i],y+Y[i],value);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        
        grid = vector<vector<int>>(n,vector<int>(m));
        visited = vector<vector<bool>>(n,vector<bool>(m,false));
        for(int i=0;i<m;i++){
            if(isSafe(heights,0,i,INT_MIN)){
                dfs(heights,0,i,1);
            }
        }        
        
        for(int i=0;i<n;i++){
            if(isSafe(heights,i,0,INT_MIN)){
                dfs(heights,i,0,1);
            }
        }
        
        visited = vector<vector<bool>>(n,vector<bool>(m,false));
        for(int i=0;i<m;i++){
            if(isSafe(heights,n-1,i,INT_MIN)){
                dfs(heights,n-1,i,2);
            }
        }        
        
        for(int i=0;i<n;i++){
            if(isSafe(heights,i,m-1,INT_MIN)){
                dfs(heights,i,m-1,2);
            }
        }
        
        vector<vector<int>> result;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==3){
                    result.push_back({i,j});
                }
            }
        }
        return result;
        
    }
};