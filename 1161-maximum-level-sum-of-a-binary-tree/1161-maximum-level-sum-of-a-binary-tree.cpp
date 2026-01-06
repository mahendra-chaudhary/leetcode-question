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
    int maxLevelSum(TreeNode* root) {


        // if(root == NULL) return 0 ; // if(!root) return 0;4

        queue<TreeNode*> q;
        q.push(root);


        int level = 1;
        int ans = 1;
        long long MaxSum = LLONG_MIN;


        while(!q.empty()){
            int n = q.size();
            long long LevelSum = 0;

            for(int i = 0;i<n;i++){

                TreeNode* node =  q.front();
                q.pop();

                LevelSum += node->val;
                  if(node->left) q.push(node->left);
                  if(node->right) q.push(node->right);
            }

            if(LevelSum > MaxSum){
                MaxSum = LevelSum;
                ans = level;
            }
            level++;


        }
        return ans;
    }
};