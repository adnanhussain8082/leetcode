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
    // recursive solution
    void preorderTraversalREC(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }

        ans.push_back(root->val);
        preorderTraversalREC(root->left, ans);
        preorderTraversalREC(root->right, ans);
    }

    // iterative(using stack)--->striver link in note
    void preorderTraversalIter(TreeNode* root, vector<int>& ans) {
        if(root==NULL) return;
        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty()){
            root=s.top();
            s.pop();
            ans.push_back(root->val);

            //if right node is present
            if(root->right){
                s.push(root->right);
            }

            //if left node is present
            if(root->left){
                s.push(root->left);
            }
        }

    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        preorderTraversalIter(root, ans);
        return ans;
    }
};