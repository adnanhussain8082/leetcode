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
    int len(ListNode* head){
        int i=1;
        ListNode* cur = head;
        while(cur->next){
            i++;
            cur = cur->next;
        }
        return i;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        int l=len(head);
        if(k==0 or k%l==0) return head;

        ListNode* cur = head , *nxt=NULL , *front=head;
        int idx = k%l;

        for(int i=1;i<l-idx;i++){
            cur=cur->next;
        }
        nxt = cur->next;
        cur->next=NULL;
        ListNode* ans = nxt;

        while(nxt->next){
            nxt=nxt->next;
        }
        nxt->next = front;

        return ans;
    }
};