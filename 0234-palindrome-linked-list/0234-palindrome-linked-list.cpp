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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        
        while(head!=NULL)
        {
            ListNode* nex=head->next;
            head->next=prev;
            prev=head;
            head=nex;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL ||head->next==NULL) return true;
        ListNode* s=head, *f=head;
        while(f->next!=NULL &&f->next->next!=NULL)
        {
            s=s->next;
            f=f->next->next;
        }
        s->next=reverse(s->next);
        s=s->next;
        while(s!=NULL)
        {
            if(s->val != head->val)
            return false;
            s=s->next;
            head=head->next;
        }
        return true;
    }
};