// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    
    bool isSafe(vector<vector<int>> & visited, int x,int y){
        int N = visited.size();
        return 0<=x && x<N && 0<=y && y<N && visited[x][y]==-1;
    }
    
    int X[8] = {-2,2,-2,2, 1, 1, -1, -1};
    int Y[8] = {1,-1,-1,1, 2,-2, 2, -2};
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    KnightPos[0]--;
	    KnightPos[1]--;
	    TargetPos[0]--;
	    TargetPos[1]--;
	    
	    vector<vector<int>> visited(N,vector<int>(N,-1));
	    
	    queue<pair<int,int>> q;
	    q.push({KnightPos[0],KnightPos[1]});
	    visited[KnightPos[0]][KnightPos[1]] = 0;
	    
	    while(!q.empty()){
	        int x = q.front().first;
	        int y = q.front().second;
	        q.pop();
	        if(x==TargetPos[0] && y==TargetPos[1]){
	            return visited[x][y];
	        }
	        
	        for(int i=0;i<8;i++){
	            if(isSafe(visited,x+X[i],y+Y[i])){
	                q.push({x+X[i],y+Y[i]});
	                visited[x+X[i]][y+Y[i]] = visited[x][y]+1;
	            }
	        }
	    }
	    
	   // return 0;
	    
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends