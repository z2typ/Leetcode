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
    int prev = INT_MIN;
    int count = 0;
    int max_count = 0;
    vector<int> ans;
    void dfs(TreeNode* root){
        if(root->left){
            dfs(root->left);
        }
        if(root->val==prev){
            count++;
        }else{
            if(max_count<count){
                max_count = count;
                ans.clear();
                if(prev!=INT_MIN)
                ans.push_back(prev);
            }else if(max_count==count){
                ans.push_back(prev);
            }
            count = 1;
        }
        prev = root->val;
        if(root->right){
            dfs(root->right);
        }
    }
    
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        if(max_count < count){
            max_count = count;
            ans.clear();
            ans.push_back(prev);
        }else if(max_count == count){
            ans.push_back(prev);
        }
        return ans;
        
    }
};