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
        unordered_set<ListNode*>mp;
        ListNode* temp=headB;
        while(temp!=NULL)
        {
            mp.insert(temp);
            temp=temp->next;
        }
        ListNode* dum=headA;
        while(dum!=NULL)
        {
            if(mp.find(dum)!=mp.end()){
                return dum;
            }
            dum=dum->next;
        }
        return NULL;
    }
};