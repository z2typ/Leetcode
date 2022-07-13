// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    vector<vector<int>> t;
    
    int util(int arr[], int i, int j){
        if(t[i][j]!=-1) return t[i][j];
        if(i==j){
            return t[i][j] = 0;
        }
        
        int temp = INT_MAX;
        for(int k=i;k<j;k++){
           temp = min(util(arr,i,k)+\
                      arr[i-1]*arr[k]*arr[j]+\
                      util(arr,k+1,j),temp);
        }
        return t[i][j]=temp;
        
        
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> t(N,vector<int>(N,-1));
        this->t = t;
        return util(arr,1,N-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends