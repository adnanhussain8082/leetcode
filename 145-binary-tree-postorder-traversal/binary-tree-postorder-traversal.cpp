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
    void postorderTraversalIter(TreeNode* root , vector<int>& ans){
        if(root == NULL) return;

        stack<TreeNode*> s1 , s2;
        s1.push(root);

        while(!s1.empty()){
            root=s1.top();
            s1.pop();
            s2.push(root);

            //if left node exists for current root node
            if(root->left){
                s1.push(root->left);
            }

            //if right node exists for current root node
            if(root->right){
                s1.push(root->right);
            }
        }

        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
    }
    void postorderTraversalREC(TreeNode* root , vector<int>& ans){
        if(root == NULL) return;

        postorderTraversalREC(root->left , ans);
        postorderTraversalREC(root->right , ans);
        ans.push_back(root->val);


    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorderTraversalIter(root , ans);
        return ans;
        
    }
};