class Solution {
public:
    vector<vector<bool>> visited;
    
    bool isSafe(vector<vector<char>> &board,char ch,int x,int y){
        int n = board.size();
        int m = board[0].size();
        return 0<=x && x<n && 0<=y && y<m && board[x][y]==ch && !visited[x][y];
    }
    
    int ans = false;
    int X[4] = {1,-1,0,0};
    int Y[4] = {0,0,-1,1};
    void dfs(vector<vector<char>>& board, string &word,int k,int x,int y){
        if(k+1==word.size()){
            ans = true;
            return;
        }
        
        visited[x][y] = true;

        for(int i=0;i<4;i++){
            if(isSafe(board,word[k+1],x+X[i],y+Y[i])){
                dfs(board,word,k+1,x+X[i],y+Y[i]);
            }
        }
        visited[x][y] = false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        visited = vector<vector<bool>>(n,vector<bool>(m,false));

        int wordSize = word.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isSafe(board,word[0],i,j)){
                    dfs(board,word,0,i,j);
                }
            }
        }
        return ans;
    }
};