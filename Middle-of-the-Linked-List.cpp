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
    ListNode* middleNode(ListNode* head) 
    {
        ListNode *tmp=head;
        int c=0;
        while(tmp!=NULL)
        {
            c++;
            tmp=tmp->next;
        }
        int m=c/2;
        tmp=head;
        while(m>0)
        {
            tmp=tmp->next;m--;
        }
        return tmp;
    }
};