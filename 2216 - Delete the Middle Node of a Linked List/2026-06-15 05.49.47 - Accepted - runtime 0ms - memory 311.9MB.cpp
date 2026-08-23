class Solution {
public:
    ListNode* deleteMiddle(ListNode* head)
    {
        if(!head || !head->next)
            return nullptr;

        int n = 0;

        ListNode* temp = head;

        while(temp)
        {
            n++;
            temp = temp->next;
        }

        int mid = n / 2;

        temp = head;

        for(int i = 0; i < mid - 1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
    }
};