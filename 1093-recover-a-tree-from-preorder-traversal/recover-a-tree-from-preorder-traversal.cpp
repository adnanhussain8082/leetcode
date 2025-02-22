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
    TreeNode* recoverFromPreorder(string traversal) {
        int n=traversal.size();
        vector<TreeNode*> stack;

        for(int i=0 , level , val;i<n;){

            for(level=0;traversal[i]=='-';i++){
                level++;
            }

            for(val=0;traversal[i]!='-' && i<n;i++){
                val = val*10 + (traversal[i]-'0');
            }
            TreeNode* node = new TreeNode(val);

            while(stack.size() > level) stack.pop_back();

            if(!stack.empty()){
                if(!stack.back()->left) stack.back()->left = node;
                else stack.back()->right = node;
            }

            stack.push_back(node);
        }
        return stack[0];
    }
};