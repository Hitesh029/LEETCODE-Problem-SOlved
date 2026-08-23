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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return nullptr;
        }
        ListNode* p1=head;
        ListNode* p2=head;
        ListNode* prev=nullptr;

        while(p2 && p2->next){
            prev=p1;
            p1=p1->next;
            p2=p2->next->next;
         }
         prev->next=p1->next;
         delete p1;
         return head;
    }
};