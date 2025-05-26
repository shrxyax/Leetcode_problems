//using merge sort and middle 

class Solution 
{
public:
    ListNode* findMiddle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* Merge(ListNode* left, ListNode* right)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        while (left != NULL && right != NULL)
        {
            if (left->val <= right->val)
            {
                cur->next = left;
                left = left->next;
            }
            else
            {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }

        if (left != NULL) cur->next = left;
        if (right != NULL) cur->next = right;

        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }

    ListNode* sortList(ListNode* head) 
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* middle = findMiddle(head);
        ListNode* right = middle->next;
        middle->next = NULL;

        ListNode* leftSorted = sortList(head);
        ListNode* rightSorted = sortList(right);

        return Merge(leftSorted, rightSorted);
    }
};
