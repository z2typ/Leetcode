class Solution {
public:
    
    vector<int> curr;
    vector<vector<int>> result;
    
    void helper(vector<int> &arr,int n, int target){

        if(target==0){
            result.push_back(curr);
            return;
        }else if(n==0){
            return;
        }
        if(arr[n-1]<=target){
            curr.push_back(arr[n-1]);
            helper(arr,n,target-arr[n-1]);
            curr.pop_back();
            helper(arr,n-1,target);
        }else{
            helper(arr,n-1,target);
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        helper(candidates,n, target);
        return result;
    }
};