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
    int count = 0;
    int util(TreeNode* root,int prevMax=INT_MIN){
        int a=0,b=0;
        if(root->left){
            a = util(root->left, max(prevMax, root->val));
        }

        if(root->right){
            b = util(root->right, max(prevMax, root->val));
        }
        
        if(root->val >= prevMax){
            return a+b+1;
        }
        return a+b;
    }
    
    int goodNodes(TreeNode* root) {
        return util(root);
    }
};