/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//first FAST!=NULL THEN FAST->NEXT!=NULL.. because agr fast is null then first.next wont exist and segmentation fault will occur;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        if(head==NULL || head->next==NULL) return nullptr;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
            {
                slow=head;
                while(slow!=fast)
                {
                    fast=fast->next;
                    slow=slow->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
        
};
