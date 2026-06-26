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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;

        ListNode* cur = head;

        while (cur != NULL && cur->next != NULL) {
            if (cur->next->val >= cur->val) {
                cur = cur->next;
            } 
            else {
                ListNode* temp = cur->next;
                cur->next = temp->next;

                ListNode* pre = dummy;
                while (pre->next->val < temp->val) {
                    pre = pre->next;
                }

                temp->next = pre->next;
                pre->next = temp;
            }
        }

        return dummy->next;
    }
};