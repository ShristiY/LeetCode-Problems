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
    ListNode* reverseKGroup(ListNode* h, int k) {
        if(k==1 || h==NULL) return h;
        ListNode* dum=new ListNode(0);
        dum->next=h;
        ListNode*prev=dum,*cur=dum,*nex=dum;
        
        int count=0;
        while(cur->next!=NULL){
            cur=cur->next;
            count++;
        }
        
        while(count>=k){
            cur=prev->next;
            nex=cur->next;
            
            for(int i=1;i<k;i++)
            {
                cur->next=nex->next;
                nex->next=prev->next;
                prev->next=nex;
                nex=cur->next;
            }
            prev=cur;
            count-=k;
        }
        return dum->next;
        
    }
};