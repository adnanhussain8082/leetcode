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
    // brute(Recursion)--0(n)
    //     if(root==NULL) return 0;
    //     int count=1;

    //     int leftAns = countNodes(root->left);
    //     int rightAns = countNodes(root->right);

    //     return count+leftAns+rightAns;

    //here using modified approach of height becoz height of side branches should be equal to apply formulla of complete tree for calculatig total nodes

    int leftHeight(TreeNode* root){
        int h=0;
        while(root){
            h++;
            root=root->left;
        }
        return h;
    }

    int rightHeight(TreeNode* root){
        int h=0;
        while(root){
            h++;
            root=root->right;
        }
        return h;
    }
    
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;

        int lh = leftHeight(root);
        int rh = rightHeight(root);
        if(lh==rh){
            return (1<<lh)-1; //or pow(2,lh-1);
        }

        //Rec
        int leftAns = countNodes(root->left);
        int rightAns = countNodes(root->right);

        return leftAns+rightAns+1;

    }
};