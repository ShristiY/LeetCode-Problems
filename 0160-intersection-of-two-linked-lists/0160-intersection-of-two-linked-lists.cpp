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
        ListNode* temp=headA;
        ListNode* l2=NULL;
        while(temp!=NULL)
        {
            l2=headB;
            while(l2!=NULL)
            {
                if(temp==l2)
                    return l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
        return NULL;
    }
};