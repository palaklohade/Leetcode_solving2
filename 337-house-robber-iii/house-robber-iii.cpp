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
unordered_map<TreeNode*, pair<int,int>> dp; 
    // dp[node] = {rob_this_node, not_rob_this_node}
    
public:
    pair<int,int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        if (dp.count(node)) return dp[node]; // DP lookup

        auto L = dfs(node->left);
        auto R = dfs(node->right);

        // If rob current node
        int rob = node->val + L.second + R.second;
        // If not rob current node
        int not_rob = max(L.first, L.second) + max(R.first, R.second);

        dp[node] = {rob, not_rob};
        return dp[node];
    }

    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
};