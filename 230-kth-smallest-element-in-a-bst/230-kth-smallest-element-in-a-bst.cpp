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
    int i = 0;
    int k;
    int ans = -1;
    void util(TreeNode* root){
        if(root->left!=NULL){
            util(root->left);
        }
        
        i++;
        if(i==k){
            ans = root->val;
        }
        if(root->right!=NULL){
            util(root->right);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        util(root);
        return ans;
    }
};