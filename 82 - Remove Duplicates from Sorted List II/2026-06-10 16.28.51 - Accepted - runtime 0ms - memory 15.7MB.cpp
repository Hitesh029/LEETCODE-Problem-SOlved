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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dumy=new ListNode(0);
        dumy->next=head;

        ListNode*prev=dumy;
        ListNode* curr = head;
        while(curr){
            if(curr->next && curr-> val ==curr->next->val){
                int dup=curr->val;

                while(curr && curr->val==dup){
                    curr=curr->next;
                }
                prev->next=curr;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }

        return dumy->next;
    }
};