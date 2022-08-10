/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int found1 = 0;
    int found2 = 0;
    TreeNode* LCA = NULL;
    void helper(TreeNode* root,TreeNode* p, TreeNode* q,TreeNode* parent){
        if(root==p || root==q){
            if(found1!=1){
                found1=1;
                LCA = root;
            }else{
                found2 = 1;
            }
        }
        if(root->left!=NULL){
            helper(root->left,p,q,root);
        }
        
        if(root->right!=NULL) { 
            helper(root->right,p,q,root);
        }
        
        if(found2!=1 && root==LCA){
            LCA = parent;
        }
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root,p,q,NULL);
        return LCA;
    }
};