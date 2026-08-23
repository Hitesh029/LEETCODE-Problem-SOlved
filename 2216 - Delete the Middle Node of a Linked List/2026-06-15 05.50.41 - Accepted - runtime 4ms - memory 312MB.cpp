class Solution {
public:
    ListNode* deleteMiddle(ListNode* head)
    {
        if(!head || !head->next)
            return nullptr;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* slow = &dummy;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = slow->next->next;

        return dummy.next;
    }
};