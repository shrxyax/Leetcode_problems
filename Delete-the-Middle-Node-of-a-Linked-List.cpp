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
    ListNode* deleteMiddle(ListNode* head) 
    {
        ListNode* tmp=head;
        int c=0;
        while(tmp!=NULL)
        {
            c++;
            tmp=tmp->next;
        }
        if(c==1) return nullptr;
        int m=c/2;
        tmp=head;
        while(m>1)
        {
            tmp=tmp->next;
            m--;
        }
        tmp->next=tmp->next->next;
        return head;

    }
};