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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry=0,m=0;
        ListNode* dummy=new ListNode;
        ListNode* curr=dummy;
        while(l1!=NULL && l2!=NULL)
        {
            m= l1->val + l2->val+carry;
            carry=m/10;
            curr->next=new ListNode(m%10);
            l1=l1->next; l2=l2->next;
            curr=curr->next;
        }
        while(l2!=NULL)
        {
            m=l2->val+carry;
            carry=m/10;
            curr->next=new ListNode(m%10);
            curr=curr->next;
            l2=l2->next;
        }
        while(l1!=NULL)
        {
            m=l1->val+carry;
            carry=m/10;
            curr->next=new ListNode(m%10);
            curr=curr->next;
            l1=l1->next;
        }
        if(carry>0)
        {
            curr->next=new ListNode(1);
            curr=curr->next;
        }
        ListNode* head=dummy->next;
        delete dummy;
        return head;
    }
};