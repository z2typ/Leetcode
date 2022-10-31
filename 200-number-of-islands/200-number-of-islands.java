class Solution {
    int visited[][];
    public int numIslands(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        visited = new int[n][m];
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    count++;
                    dfs(i,j,grid,n,m);
                }
            }
        }
        return count;
    }
    public void dfs(int i,int j,char grid[][],int n,int m){
        if(visited[i][j]==0){
            visited[i][j]=-1;
            if(i+1<n && grid[i+1][j]=='1' && visited[i+1][j]==0){
                dfs(i+1,j,grid,n,m);
            }
            if(j+1<m && grid[i][j+1]=='1' && visited[i][j+1]==0){
                dfs(i,j+1,grid,n,m);
            }
            if(i-1>=0 && grid[i-1][j]=='1' && visited[i-1][j]==0){
                dfs(i-1,j,grid,n,m);
            }
            if(j-1>=0 && grid[i][j-1]=='1' && visited[i][j-1]==0){
                dfs(i,j-1,grid,n,m);
            }
        }
    }
}
