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

    ListNode* getK(ListNode* curr, int k){
        while(curr && k--){
            curr=curr->next;
        }
        return curr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;

        ListNode* grouprev=dummy;

        while(true){
            ListNode* kth=getK(grouprev,k);
            if(kth==NULL)
                break;
            ListNode* groupnext=kth->next;
            ListNode* prev=groupnext;
            ListNode* curr =grouprev->next;
            while(curr!=groupnext){
                ListNode* temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
            }    
            ListNode* temp =grouprev->next;
            grouprev->next=kth;
            grouprev=temp;

        }
        return dummy->next;
        
    }
};