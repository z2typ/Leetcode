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
    void util(TreeNode* root,int prevMax=INT_MIN){
        if(root->left){
            util(root->left, max(prevMax, root->val));
        }
        if(root->val >= prevMax){
            count++;
        }
        if(root->right){
            util(root->right, max(prevMax, root->val));
        }
    }
    
    int goodNodes(TreeNode* root) {
        util(root);
        return count;
    }
};