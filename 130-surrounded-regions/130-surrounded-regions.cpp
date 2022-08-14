class Solution {
public:
    vector<vector<bool>> visited;
    bool isSafe(vector<vector<char>> &board,int x,int y){
        int n = board.size();
        int m = board[0].size();
        return 0<=x && x<n && 0<=y && y<m && board[x][y]!='X' && !visited[x][y];
    }
    int X[4] = {0,0,1,-1};
    int Y[4] = {-1,1,0,0};
    void dfs(vector<vector<char>> &board,int x,int y){
        
        visited[x][y] = true;
        
        for(int i=0;i<4;i++){
            if(isSafe(board,x+X[i],y+Y[i])){
                dfs(board,x+X[i],y+Y[i]);
            }
        }
        
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        visited = vector<vector<bool>>(n,vector<bool>(m,false));
        
        for(int i=0;i<m;i++){
            if(isSafe(board,0,i)){
                dfs(board,0,i);
            }
            if(isSafe(board,n-1,i)){
                dfs(board,n-1,i);
            }
        }
        for(int i=0;i<n;i++){
            if(isSafe(board,i,0)){
                dfs(board,i,0);
            }
            if(isSafe(board,i,m-1)){
                dfs(board,i,m-1);
            }
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && visited[i][j]==false){
                    board[i][j]='X';
                }
            }
        }

        
    }
};