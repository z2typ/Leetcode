/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* arrToBST(vector<int>& arr,int i,int j){
        TreeNode* root = NULL;
        if(i<=j){
            int mid = (i+j)/2;
            root = new TreeNode(arr[mid]);
            root->left = arrToBST(arr,i,mid-1);
            root->right = arrToBST(arr,mid+1,j);
        }
        return root;
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return arrToBST(nums,0,n-1);
    }
};