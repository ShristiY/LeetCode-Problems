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
    ListNode* middleNode(ListNode* head) {
        int len=0;
        ListNode* dum=head;
        while(dum!=NULL)
        {
           dum=dum->next;
            len++;
        }
        
        int hLen=len/2;
        ListNode* ans=head;
        while(hLen!=0)
        {
            hLen--;
            ans=ans->next;
        }
        return ans;
    }
};