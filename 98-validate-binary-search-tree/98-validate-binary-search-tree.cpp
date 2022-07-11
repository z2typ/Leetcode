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
    bool isValidBST_util(TreeNode* root, long long left, long long right){
        if(root==NULL){
            return true;
        }
        
        if(left<root->val && root->val<right)
            if(isValidBST_util(root->left,left,root->val)&&isValidBST_util(root->right,root->val,right)){
            return true;
        }
        return false;
    }
    
    bool isValidBST(TreeNode* root) {
        
        return isValidBST_util(root,LLONG_MIN,LLONG_MAX);
    }
};