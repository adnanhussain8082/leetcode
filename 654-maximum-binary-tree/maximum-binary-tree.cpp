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
    TreeNode* helper(vector<int>& nums ,unordered_map<int,int>& mpp , int left , int right){
        //base case
        if(left > right){
            return NULL;
        }

        //find the max element from current array
        auto maxEle = max_element(nums.begin()+left , nums.begin()+right+1);

        //create a node
        TreeNode* root = new TreeNode(*maxEle); //derefencing pointer

        int Ele_index = mpp[*maxEle];

        //REC
        root->left = helper(nums , mpp , left , Ele_index-1);
        root->right = helper(nums , mpp , Ele_index+1 , right);

        return root;

    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        //initialize map to store indexes of nums elements
        unordered_map<int ,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]=i;
        }

        return helper(nums , mpp , 0 , nums.size()-1);
    }
};