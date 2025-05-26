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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL || head->next==NULL) return head;
        ListNode* tmp=head;
        int c=0;
        ListNode* dummy=new ListNode;
        while(tmp!=NULL)
        {
            c++;
            tmp=tmp->next;
        }
        if(k==c) return head;
        dummy->next=head;
        tmp=dummy;
        k=k%c;
        int m=c-k;
        while(m>0)
        {
            tmp=tmp->next;
            m--;
        }
        ListNode* ele=tmp;
        while(tmp->next!=NULL)
        {
            tmp=tmp->next;
        }
        tmp->next=head;
        ListNode* new_head=ele->next;
        ele->next=NULL;
        head=new_head;
        dummy->next=NULL;
        delete dummy;
        return head;
    }
};