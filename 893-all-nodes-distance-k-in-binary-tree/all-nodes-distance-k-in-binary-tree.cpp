/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void track_parents(TreeNode* root , TreeNode* target , unordered_map<TreeNode* , TreeNode*>& parent_track){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();

            if(current->left){
                parent_track[current->left] = current;
                q.push(current->left);
            }

            if(current->right){
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> parent_track;

        track_parents(root , target , parent_track);

        unordered_map<TreeNode*,bool> vis;
        vis[target]=true;

        queue<TreeNode*> q;

        q.push(target);

        int cnt=0;

        while(!q.empty()){

            int sz=q.size();
            if(cnt==k) break;
            cnt++;

            for(int i=0;i<sz;i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left and !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left]=true;
                }

                if(curr->right and !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right]=true;
                }

                if(parent_track[curr] and !vis[parent_track[curr]]){
                    q.push(parent_track[curr]);
                    vis[parent_track[curr]]=true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;

    }
};