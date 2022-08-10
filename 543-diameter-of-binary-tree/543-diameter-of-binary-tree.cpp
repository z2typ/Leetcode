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
    int diameter = 0;
    int util(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        int left_height = util(root->left);
        int right_height = util(root->right);
        diameter = max(diameter,left_height+right_height+1);
        return max(left_height,right_height)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        util(root);
        return diameter-1;
    }
};