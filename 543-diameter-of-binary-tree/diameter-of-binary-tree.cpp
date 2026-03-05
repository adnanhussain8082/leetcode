/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root) {
        // base case -> empty tree has height 0
        if (root == NULL) {
            return 0;
        }
        // left tree height
        int leftHeight = height(root->left);
        // right tree height
        int rightHeight = height(root->right);
        // max of left subtree and right subtree and +1 to consider the root
        // node
        int ans = max(leftHeight, rightHeight) + 1;
        // return the height
        return ans;
    }
    int diameterBinaryTree(TreeNode* root) {
        // Base case -> empty tree
        if (root == NULL) {
            return 0;
        }
        // left subtree check
        int op1 = diameterBinaryTree(root->left);
        // right subtree check
        int op2 = diameterBinaryTree(root->right);
        // case when root node is included in the answer
        int op3 = height(root->left) + height(root->right);
        // we have to choose the longest path and hence max is taken
        int ans = max(op1, max(op2, op3));
        // return diameter
        return ans;
    }


    
    //       optimisation


    pair<int,int> diameterFast(TreeNode* root){
        if(root==NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }

        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second;

        pair<int,int> ans;
        ans.first = max(op1 , max(op2 , op3));
        ans.second = max(left.second , right.second)+1;

        return ans;

    }


    int diameterOfBinaryTree(TreeNode* root) {
        // return diameterBinaryTree(root);
        pair<int,int> ans = diameterFast(root);
        return ans.first;
    }
};