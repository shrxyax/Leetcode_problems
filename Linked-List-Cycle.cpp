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
    bool hasCycle(ListNode *head) 
    {
       ListNode* tmp=head;
       vector<ListNode*> v;
       while(tmp!=NULL)
       {
          for(int i=0;i<v.size();i++)
          {
            if(tmp==v[i]) return true;
          }
          v.push_back(tmp);
          tmp=tmp->next;
       } 
       return false;
    }
};