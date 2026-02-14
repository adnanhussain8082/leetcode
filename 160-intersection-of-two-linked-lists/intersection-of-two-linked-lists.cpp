/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //intuition : Switching starts cancels the extra distance difference.
        ListNode *a = headA , *b = headB;

        while(a!=b){
            a = (a!=NULL) ? a->next : headB;
            b = (b!=NULL) ? b->next : headA;
        }

        return a;
    }
};