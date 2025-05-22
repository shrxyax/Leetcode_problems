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
    bool isPalindrome(ListNode* head) 
    {
        int c=0;
        if(head->next==NULL) return true;
        ListNode* tmp=head;
        while(tmp!=NULL)
        {
            tmp=tmp->next;
            c++;
        }
        int m=c/2;
        tmp=head;
        while(m>1)
        {
            tmp=tmp->next;m--;
        }
        ListNode* prev=NULL;
        if(tmp->next->next==NULL)
        {
            if(tmp->next->val==head->val) return true;
            else return false;
        }
        ListNode* curr=tmp->next;
        while(curr!=NULL)
        {
            ListNode* newnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=newnode;
        }
        m=c/2;
        for(int i=1;i<=m;i++)
        {
            if(head->val!=prev->val) return false;
            head=head->next;
            prev=prev->next;
        }
        return true;
    }
};