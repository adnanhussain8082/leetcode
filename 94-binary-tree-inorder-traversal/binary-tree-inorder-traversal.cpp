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
                //recursive solution
    void inorderTraversalHelper(TreeNode* root , vector<int>& ans){
        if(root==NULL){
            return;
        }

        inorderTraversalHelper(root->left , ans);

        ans.push_back(root->val);

        inorderTraversalHelper(root->right , ans);

    }
     
                 //iterative solution(using stack)
    void inorderTraversalIterative(TreeNode* root , vector<int>& ans){

        stack<TreeNode*> s;
        TreeNode* current = root;

        while(current != NULL || !s.empty()){
            while(current != NULL){
                s.push(current);
                current=current->left;
            }

            current = s.top();
            s.pop();
            ans.push_back(current->val);
            current=current->right;
        }

    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorderTraversalIterative(root , ans);
        return ans;

    }
};