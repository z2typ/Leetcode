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
        
        if(p->left==NULL && q->left!=NULL || p->left!=NULL && q->left==NULL ){
            isSame = false;
        }else{
            util(p->left,q->left);
        }
        
        if(p->right==NULL && q->right!=NULL || p->right!=NULL && q->right==NULL ){
            isSame = false;
        }else{
            util(p->right,q->right);
        }
        
        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        util(p,q);
        return isSame;
    }
};