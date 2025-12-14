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
    // useing dfs method can use 
    // void dfs(TreeNode* root,int level,vector<int>& ans){
    //     if(!root) return ;

    //     if(level == ans.size()){
    //         ans.push_back(root->val);
    //     }
    //     else{
    //         ans[level] = root->val;
    //     }
    //     dfs(root->left,level+1,ans);
    //     dfs(root->right,level+1,ans);
    // }
    vector<int> rightSideView(TreeNode* root) {

        // vector<int> ans;
        // dfs(root,0,ans);

        // return ans;


        // using bfs process 

        vector<int>ans;
        if(!root) return ans;

        queue<TreeNode*> q ;
        q.push(root);

        // TreeNode* node = root;

        while(!q.empty()){

            int size = q.size();

            for(int i = 0;i<size;i++){

                TreeNode* node = q.front();
                q.pop();


            if(i == size -1){
                ans.push_back(node->val);

            }

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            }

        }

        return ans;



        
    }
};