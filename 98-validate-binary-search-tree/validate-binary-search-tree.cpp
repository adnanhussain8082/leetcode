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
    bool isValidBST_helper(TreeNode* root , long long minVal , long long maxVal){
        if(root==NULL) return true; // means we are at the last node and every node above follows the BST conditions

        if(root->val <= minVal || root->val >= maxVal) return false;

        return isValidBST_helper(root->left , minVal , root->val) && isValidBST_helper(root->right , root->val , maxVal);

    }
    bool isValidBST(TreeNode* root) {
        return isValidBST_helper(root , LLONG_MIN, LLONG_MAX);
    }
};