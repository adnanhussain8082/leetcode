/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

//iterative approach o(n) space
// class Solution {
// public:
//     Node* connect(Node* root) {
//         // Node* cur = root;
//         if(root==NULL) return NULL;
//         queue<Node*> q;
//         q.push(root);

//         while(!q.empty()){
//             int sz = q.size();

//             for(int i=0;i<sz;i++){
//                 Node* cur = q.front();
//                 q.pop();

//                 if(cur->left) q.push(cur->left);
//                 if(cur->right) q.push(cur->right);

//                 if(i==sz-1){
//                     cur->next = NULL;
//                 }
//                 else{
//                     cur->next = q.front();
//                 }
//             }
//         }
//         return root;
//     }
// };




//recursive approach o(1) space 

class Solution {
private:
    void f(Node* root){
        if(root==NULL) return;

        Node *L=root->left , *R=root->right , *N=root->next;

        if(L){
            L->next = R;
            if(N) R->next = N->left;

            f(root->left);
            f(root->right);
        }
    }
public:
    Node* connect(Node* root) {
        f(root);
        return root;
    }
};