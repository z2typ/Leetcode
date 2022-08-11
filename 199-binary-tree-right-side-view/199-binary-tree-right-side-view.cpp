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
    int max_level = -1;
    vector<int> rightView;
    void rightSide(TreeNode* root,int level = 0){
        if(root==NULL)return;
        if(level>max_level){
            rightView.push_back(root->val);
            max_level = level;
        }
        
        rightSide(root->right,level+1);
        rightSide(root->left,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        rightSide(root);
        return rightView;
    }
};