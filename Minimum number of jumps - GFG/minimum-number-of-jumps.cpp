// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        if(arr[0]==0 && n>1) return -1;
        if(arr[0]==0 && n==1) return 0; 
        int i = 0;
        int j = 0;
        int count = 0;
        int max_jump = arr[0];
        while(j<n-1 && i<=j){
            i = j+1;
            j = max_jump;
            for(int k=i;k<=min(j,n-1);k++){
                max_jump = max(max_jump,arr[k]+k);
                
            }
            count++;
        }
        if(j<i) return -1;
        return count;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends