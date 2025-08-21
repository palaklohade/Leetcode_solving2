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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,int inStart, int inEnd, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd) return nullptr;

        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = -1;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == rootVal) {
                inIndex = i;
                break;
            }
        }

        int leftSize = inIndex - inStart;

        root->left = helper(inorder, postorder, inStart, inIndex - 1, postStart, postStart + leftSize - 1);

        root->right = helper(inorder, postorder,inIndex + 1, inEnd, postStart + leftSize, postEnd - 1);

        return root;
        
    }
};