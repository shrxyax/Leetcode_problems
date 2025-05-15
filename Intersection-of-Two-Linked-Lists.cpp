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
    
        ListNode *tmpA=headA;
        ListNode *tmpB=headB;
        while(tmpA!=NULL)
        {
            tmpB=headB;
            while(tmpB!=NULL)
            {
                if(tmpA==tmpB) return tmpA;
                tmpB=tmpB->next;
            }
            tmpA=tmpA->next;
        }
        return NULL;
    }
};