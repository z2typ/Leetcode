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
    void dfs(TreeNode* root,vector<int> &ans,int len, int &longest_len){
        if(root==NULL){
            return;
        }
        if(longest_len<len){
            longest_len = len;
            ans.push_back(root->val);
        }
        dfs(root->right,ans,len+1,longest_len);
        dfs(root->left,ans,len+1,longest_len);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        int length = -1;
        vector<int> ans;
        dfs(root,ans,0,length);
        return ans;
    }
};