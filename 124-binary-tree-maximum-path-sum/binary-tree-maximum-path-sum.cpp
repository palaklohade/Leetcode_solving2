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
    int maxsum;
    int dfs(TreeNode* root){
        if(!root)return 0;
        int left = max(0, dfs(root->left) );
        int right = max(0, dfs(root->right) );
        maxsum = max(maxsum , root->val + left+ right);
        return root->val + max(left,right);

    }
    int maxPathSum(TreeNode* root) {
        maxsum = INT_MIN;
        dfs(root);
        return maxsum;
    }
};