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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       
        ListNode* dum=head;
        int len=0;
        while(dum!=NULL)
        {
            dum=dum->next;
            len++;
        }
        ListNode* node=head;
        int req=len-n;
        if(req==0)
            return head->next;
        else{
            int t=0;
        while(t!=req-1)
        {
            t++;
            node=node->next;
        }
        node->next=node->next->next;
        }
        return head;
    }
};