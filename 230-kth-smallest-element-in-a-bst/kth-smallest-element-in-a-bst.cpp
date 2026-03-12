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
    void inorder(TreeNode* root , int& k , int& count , int& ans){
        //base case
        if(root==NULL or count >= k) return;

        //left call
        if(root->left){
            inorder(root->left , k , count , ans);
        }

        count++;  //increment the count as one node has been visited

        
        if(count == k){
            ans = root->val;
            return;
        }

        
        if(root->right){
            inorder(root->right , k , count , ans);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        int count=0;

        inorder(root , k , count , ans);

        return ans;
    }
};