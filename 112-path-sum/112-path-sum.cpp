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
    
    bool dfs(TreeNode* root,int targetSum,int currPathSum=0){
        if(root==NULL) return false;
        if(root->left==NULL && root->right == NULL){
            if(currPathSum + root->val == targetSum)
                return true;
            return false;
        }

        if(dfs(root->left, targetSum, currPathSum + root->val) ||
           dfs(root->right, targetSum, currPathSum + root->val)){
            return true;
        }
        return false;
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root,targetSum);
    }
};