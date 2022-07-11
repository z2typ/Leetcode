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
    bool util(TreeNode* root,TreeNode* p, TreeNode* q, TreeNode* &ans){
        bool current = false, left_st = false, right_st = false;
        
        if(root==NULL){
            return false;
        }
        
        if(root == p || root == q){
            current = true;
        }
        
        left_st = util(root->left, p,q,ans);
        
        right_st = util(root->right ,p,q,ans);
                
        if(ans==NULL && ((left_st&&current)||(current&&right_st)||(left_st&&right_st) ) ){
            ans = root;
        }
        

        return current||right_st||left_st;
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* ans=NULL;
        
        util(root,p,q,ans);
        
        return ans;
    }
};