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
    
    int dfs(vector<vector<int>> &matrix, int x,int y){
        if(visited[x][y]){
            return visited[x][y];
        }
        int max_depth = 1;
        
        for(int i=0;i<4;i++){                
            
            if(isSafe(matrix, x+X[i], y+Y[i], matrix[x][y])){
                max_depth = max(max_depth,dfs(matrix,x+X[i],y+Y[i])+1);
                
            }
        }
        
        visited[x][y] = max_depth;
        return max_depth;
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        visited = vector<vector<int>>(n,vector<int>(m));
        int max_length = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]){
                    max_length = max(max_length, dfs(matrix,i,j));
                }else{
                    max_length = max(max_length, visited[i][j]);
                }
            }
        }
        max_length = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout<<visited[i][j]<<" ";
                max_length = max(max_length,visited[i][j]);
            }
            // cout<<endl;
        }
        
        return max_length;
        
    }
};