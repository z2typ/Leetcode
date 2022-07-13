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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root==NULL) return vector<vector<int>>(0,vector<int>(0));
        
        queue<TreeNode*> q;
        
        vector<vector<int>> bft;
        bft.push_back({root->val});
        
        q.push(root);
        
        while(!q.empty()){

            int n = q.size();
            vector<int> level;
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left!=NULL){
                    level.push_back(node->left->val);
                    q.push(node->left);
                }

                if(node->right!=NULL){
                    level.push_back(node->right->val);
                    q.push(node->right);
                }
            }
            if(!level.empty())
            bft.push_back(level);
            
        }
        
        return bft;

        
    }
};