/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {

        return dfs(root,false);   
    }

    int dfs(TreeNode* root , bool isleft){
        if(!root) return NULL;
        if(!root->left && !root->right) return isleft ? root->val :0;

    

    return dfs(root->left,true) + dfs(root->right , false);
    }
};