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
    // void dfs(TreeNode* root, vector<int>& ans){

    //     if(!root) return;

    //     dfs(root->left,ans);
    //     dfs(root->right,ans);
    //     ans.push_back(root->val);
    // }
    vector<int> postorderTraversal(TreeNode* root) {
        // 1st method recursive
    // vector<int>ans ;

    // dfs(root,ans);

    // return ans;
    // 2nd method  iterative
        vector<int> ans;
        if(!root) return ans ;

        stack<TreeNode*> st;
        // st.push(curr);

        TreeNode* curr =  root;
        TreeNode* lastvisited = nullptr;


        while( curr || !st.empty()){
            if(curr){
                st.push(curr);
                curr = curr->left;
            }
            else{
                TreeNode* node = st.top();
                if(node->right && lastvisited != node->right){
                    curr = node->right;

                }
                else{
                    ans.push_back(node->val);
                    lastvisited = node;
                    st.pop();
                }
            }
        }
        return ans;
    //      vector<int> ans;

    //       if(!root ) return ans;

    //       stack<TreeNode*> st;
    //       st.push(root);

    //       while(!st.empty()){

    //         TreeNode* node =  st.top();
    //         st.pop();
    //         ans.push_back(node->val);

    //         if(node->left) st.push(node->left);
    //         if(node->right) st.push(node->right);

    //       }
       
    //    return ans;



        
        
    }
};