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
    
        ListNode* tmp=headA;
        while(tmp->next!=NULL)
        {
            tmp=tmp->next;
        }
        tmp->next=headA;
        ListNode* fast=headB;
        ListNode* slow=headB;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
            {
                slow=headB;
                while(fast!=slow)
                {
                    fast=fast->next;
                    slow=slow->next;
                }
                tmp->next=NULL;
                return slow;
            }
        }
        tmp->next=NULL;
        return NULL;
    }
};