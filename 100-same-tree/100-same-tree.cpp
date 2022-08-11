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
    bool isSame = true;
    void util(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL){
            return;
        }if(p==NULL || q==NULL){
            isSame = false;
            return;
        }
        if(p->val != q->val){
            isSame = false;
        }
        
            
        util(p->left,q->left);    
        util(p->right,q->right);

        
        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        util(p,q);
        return isSame;
    }
};