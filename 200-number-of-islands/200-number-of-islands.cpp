class Solution {
public:
    
    vector<vector<bool>> visited;
    
    bool isSafe(vector<vector<char>> &grid, int x, int y){
        int n = grid.size();
        int m = grid[0].size();
        return 0<=x && x<n && 0<=y && y<m && grid[x][y]=='1' && !visited[x][y];
    }
    
    int X[4] = {1,0,-1,0};
    int Y[4] = {0,1,0,-1};
    
    void dfs(vector<vector<char>> &grid, int x, int y){
        visited[x][y] = true;
        for(int i=0;i<4;i++){
            if(isSafe(grid,x+X[i],y+Y[i])){
                dfs(grid,x+X[i],y+Y[i]);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        visited = vector<vector<bool>>(n,vector<bool>(m));
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isSafe(grid, i,j)){
                    dfs(grid,i,j);
                    count += 1;
                }
            }
        }
        return count;
        
    }
};