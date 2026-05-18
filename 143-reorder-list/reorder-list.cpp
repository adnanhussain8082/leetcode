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
    void reorderList(ListNode* head) {

        if(!head || !head->next) return;

        ListNode *slow = head, *fast = head;

        // find middle
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // split list
        ListNode *nextHalfHead = slow->next;
        slow->next = NULL;

        // reverse second half
        ListNode *curr = nextHalfHead, *prev = NULL;

        while(curr){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // merge two halves
        ListNode *first = head, *second = prev;

        while(second){

            ListNode *temp1 = first->next;
            ListNode *temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};