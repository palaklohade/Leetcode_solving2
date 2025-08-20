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
    TreeNode* searchBST(TreeNode* root, int val) {
        // if(!root)return nullptr;
        // if(val == root->val){
        //     return root;
        // }else if (val < root->val){
        //    return searchBST(root->left, val);
        // }else{
        //    return searchBST(root->right, val);
        // }
        //this is the recussion stack;
        // t = o(n)
        // s = o(h)
        while(root){
            if(root->val ==val)return root;
            else if(root->val > val) root = root->left;
            else root = root->right;
        }
        return nullptr;
    }//this is the iterative method ;  
    //t = o(n)
    //s = o(1)
};