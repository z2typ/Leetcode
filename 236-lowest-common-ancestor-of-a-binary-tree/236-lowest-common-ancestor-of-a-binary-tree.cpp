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
    bool found1 = false;
    bool found2 = false;
    TreeNode* LCA = NULL;
    
    void helper(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode* parent){
        if(root==NULL){
            return;
        }
        
        if(root==p||root==q){
            if(found1==false){
                found1 = true;
                LCA = root;
            }
            else{
                found2 = true;
            }
        }
        
        helper(root->left,p,q,root);
        
        helper(root->right,p,q,root);
        
        if(root==LCA && found2==false){
            LCA = parent;
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root,p,q,NULL);
        return LCA;
    }
};