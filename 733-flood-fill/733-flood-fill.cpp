class Solution {
public:
    vector<vector<bool>> visited;
    bool isSafe(vector<vector<int>>& image, int x, int y, int color){
        int n = image.size();
        int m = image[0].size();
        return 0<=x && x<n && 0<=y && y<m && image[x][y]==color && !visited[x][y];
    }
    int X[4] = {1,-1,0,0};
    int Y[4] = {0,0,-1,1};
    void dfs(vector<vector<int>>& image, int sr, int sc, int color){
        int currColor = image[sr][sc];
        image[sr][sc] = color;
        visited[sr][sc] = true;
        for(int i=0;i<4;i++){
            if(isSafe(image,sr+X[i],sc+Y[i],currColor)){
                dfs(image,sr+X[i],sc+Y[i],color);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        visited = vector<vector<bool>>(n,vector<bool>(m));
        dfs(image,sr,sc,color);
        return image;
    }
};