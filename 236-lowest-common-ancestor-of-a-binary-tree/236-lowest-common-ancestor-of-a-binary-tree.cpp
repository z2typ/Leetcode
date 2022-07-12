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
    void util(TreeNode* root,TreeNode* p, TreeNode* q, TreeNode* &ans,TreeNode* parent = NULL){
        
        
        
        if(root==p || root==q){
            if(found1 == false){
                ans = root;
                found1=true;
            }else{
                found2 = true;
            }

        }
        
        if(root->left!=NULL)
        util(root->left,  p, q, ans, root);
        if(root->right!=NULL)
        util(root->right, p, q, ans, root);
        
        if(found1==true && found2!=true && ans==root){
            ans=parent;
        }
        
        
        
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* ans=NULL;
        
        util(root,p,q,ans);
        
        return ans;
    }
};