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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        ListNode *temp1=l1 , *temp2=l2;

        int carry=0;

        while(temp1 and temp2){
            int val = temp1->val + temp2->val + carry;
            int num = val%10;
            carry = val/10;

            temp->next = new ListNode(num);
            temp = temp->next;

            temp1=temp1->next;
            temp2=temp2->next;

        }

        while(temp1){
            int val = temp1->val + carry;
            int num = val%10;
            carry = val/10;

            temp->next = new ListNode(num);
            temp = temp->next;

            temp1=temp1->next;

        }
        if(carry){
            temp->next = new ListNode(carry);
        }

        while(temp2){
            int val = temp2->val + carry;
            int num = val%10;
            carry = val/10;

            temp->next = new ListNode(num);
            temp = temp->next;

            temp2=temp2->next;

        }
        if(carry){
            temp->next = new ListNode(carry);
        }

        return dummy->next;
    }
};