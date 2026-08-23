class Solution {
public:
    int pairSum(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = slow;
        ListNode* next = NULL;

        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        int ans = 0;

        while(prev)
        {
            ans = max(ans, head->val + prev->val);

            head = head->next;
            prev = prev->next;
        }

        return ans;
    }
};