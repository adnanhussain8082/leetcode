/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    //ist method by calculating length
    ListNode* f1(ListNode* head){
        int len=1;
        ListNode* temp=head;
        while(temp->next!=NULL){
            len++;
            temp=temp->next;
        }

        int i=0;
        ListNode* cur=head;
        while(i<len/2){
            i++;
            cur=cur->next;
        }
        return cur;
    }
public:
    ListNode* middleNode(ListNode* head) {
        if(head->next==NULL) return head; //only one node

        //two methods
        return f1(head);

        
    }
};