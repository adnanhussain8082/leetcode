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

class FindElements {
private:

    unordered_set<int> seen;

    void dfs(TreeNode* root , int value){
        if(root==NULL) return;

        root->val=value;
        seen.insert(value);

        dfs(root->left , 2*root->val + 1);
        dfs(root->right , 2*root->val + 2); 
    }
public:
    FindElements(TreeNode* root) {
        dfs(root , 0);
    }
    
    bool find(int target) {
        return seen.find(target) != seen.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */