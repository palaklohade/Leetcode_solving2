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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int preStart, int preEnd,int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = -1;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == rootVal) {
                inIndex = i;
                break;
            }
        }

        int leftSize = inIndex - inStart;

        root->left = helper(preorder, inorder, preStart + 1, preStart + leftSize,inStart, inIndex - 1);

        root->right = helper(preorder, inorder,preStart + leftSize + 1, preEnd, inIndex + 1, inEnd);

        return root;
     }
};