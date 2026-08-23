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

    ListNode* merge(ListNode*l1,ListNode* l2){
        ListNode dummy(0);
        ListNode* tail =&dummy;

        while(l1&&l2){
            if(l1->val<l2->val){
                tail->next=l1;
                l1=l1->next;
            }
            else{
                tail->next=l2;
                l2=l2->next;
            }
            tail=tail->next;
        }
        tail->next=l1?l1:l2;
        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& list) {
        if(list.empty())
           return NULL;
        while(list.size()>1){
            vector<ListNode*> temp;
            for(int i=0; i<list.size(); i+=2){
                ListNode* l1=list[i];
                ListNode* l2=(i+1<list.size())?list[i+1]:NULL;
                temp.push_back(merge (l1,l2));
            }
            list=temp;
        }   
        return list[0];

    }
};