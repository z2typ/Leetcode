#define MOD 1'000'000'007
class Solution {
public:
    vector<vector<int>> visited;
    
    bool isSafe(vector<vector<int>> &matrix, int x,int y, int currVal = INT_MIN){
        int n = matrix.size();
        int m = matrix[0].size();
        
        return 0<=x && x<n && 0<=y && y<m && (matrix[x][y] > currVal);
    }
    
    int X[4] = {0,0,-1,1};
    int Y[4] = {-1,1,0,0};
    
    int add(long long a,long long b){
        return ((a%MOD)+(b%MOD))%MOD;
    }
    
    int dfs(vector<vector<int>> &matrix, int x,int y){
        
        if(visited[x][y]){
            return visited[x][y];
        }
        
        int paths = 0;
        for(int i=0;i<4;i++){                
            if(isSafe(matrix, x+X[i], y+Y[i], matrix[x][y])){
                paths = add(paths,dfs(matrix,x+X[i],y+Y[i])+1);
            }
        }
        return visited[x][y] = paths;
        
    }
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        visited = vector<vector<int>>(n,vector<int>(m));
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                count = add(count, dfs(grid,i,j)+1);
            }
        }
        return count;
    }
};