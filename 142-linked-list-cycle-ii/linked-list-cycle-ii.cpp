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
    ListNode *detectCycle(ListNode *head) {
        ListNode* nodeFinder=head;
        ListNode* walker=head;
        ListNode* runner=head;

        while(runner!=NULL && runner->next!=NULL){
            walker=walker->next;
            runner=runner->next->next;

            if(walker==runner){
                while(nodeFinder != walker){
                    walker=walker->next;
                    nodeFinder=nodeFinder->next;
                }
                return nodeFinder;
            }
        }
        return NULL;
    }
};