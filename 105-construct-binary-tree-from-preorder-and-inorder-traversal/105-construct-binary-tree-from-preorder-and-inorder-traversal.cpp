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
    unordered_map<int,int> inOrderIdx;
    int idx = 0;
    TreeNode* buildT(vector<int>&po,int l,int r){
        if(idx==po.size()) return NULL;
        
        TreeNode* root = new TreeNode(po[idx]);
        int inIdx = inOrderIdx[root->val];
        if(l < inIdx){
            idx++;
            root->left = buildT(po,l,inIdx-1);
        }
        if(inIdx < r){
            idx++;
            root->right = buildT(po,inIdx+1,r);
        }
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int,int> inOrderIdx;
        
        for(int i=0;i<n;i++){
            inOrderIdx[inorder[i]] = i;
        }
        this->inOrderIdx = inOrderIdx;
        
        return buildT(preorder,0,n-1);
    }
};