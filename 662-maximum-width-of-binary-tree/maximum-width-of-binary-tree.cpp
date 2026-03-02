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
    int widthOfBinaryTree(TreeNode* root) {
        //explaination of Error in notes
        if(root==NULL){
            return 0;
        }
        int ans=0;
        queue<pair<TreeNode* , int>> q;
        q.push({root , 0}); //default index as 0 for root node

        while(!q.empty()){
            int size = q.size();
            int mmin = q.front().second;
            int first=0 , last=0;

            for(int i=0;i<size;i++){
                int cur_id = q.front().second-mmin;
                TreeNode* node = q.front().first;
                q.pop();

                if(i==0) first = cur_id;
                if(i==size-1) last = cur_id;

                if(node->left){
                    q.push({node->left , (long long)2*cur_id+1}); //typeCasting
                }

                if(node->right){
                    q.push({node->right , (long long)2*cur_id+2}); //typeCasting
                }
            }
            //ouside for loop
            ans=max(ans , last-first+1);
        }
        return ans;
    }
};
