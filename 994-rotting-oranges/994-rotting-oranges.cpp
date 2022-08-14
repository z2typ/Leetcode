struct coordinate{
    int x;
    int y;
};
class Solution {
public:
    vector<vector<int>> visited;
    bool isSafe(vector<vector<int>> &grid,int x,int y){
        int n = grid.size();
        int m = grid[0].size();
        return 0<= x && x<n && 0<=y && y<m && grid[x][y]==1 && !visited[x][y];
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        visited = vector<vector<int>>(n,vector<int>(m,false));
        queue<coordinate> rotton;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    rotton.push({i,j});
                    visited[i][j] = true;
                    // cout<<i<<","<<j<<endl;
                }
            }
        }
        int X[4] = {0,0,-1,1};
        int Y[4] = {-1,1,0,0};
        int time = 0;
        
        while(!rotton.empty()){
            int q_size = rotton.size();
            for(int i=0;i<q_size;i++){
                int x = rotton.front().x;
                int y = rotton.front().y;
                rotton.pop();
                visited[x][y] = true;
                for(int j=0;j<4;j++){
                    if(isSafe(grid,x+X[j],y+Y[j])){
                        visited[x+X[j]][y+Y[j]] = true;
                        rotton.push({x+X[j],y+Y[j]});
                    }
                }
            }
            
            time += 1;

        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]==false){
                    return -1;
                }
            }
        }
        return time==0 ? 0 : time-1;
        
    }
};