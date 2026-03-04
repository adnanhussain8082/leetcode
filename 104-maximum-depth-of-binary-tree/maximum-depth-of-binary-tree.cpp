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
    int maxDepthHelper(TreeNode* root){
        //base case
        if(root==NULL){
            return 0;
        }

        //soln for one case
        int leftHeight = 1 + maxDepthHelper(root->left);
        int rightHeight = 1 + maxDepthHelper(root->right);

        if(leftHeight>rightHeight){
            return leftHeight;
        }
        else{
            return rightHeight;
        }

    }
    int maxDepth(TreeNode* root) {
        return maxDepthHelper(root);
    }
};