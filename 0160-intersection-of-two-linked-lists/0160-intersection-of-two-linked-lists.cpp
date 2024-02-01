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
    
    int getDiff(ListNode*h1, ListNode*h2){
        int len1=0,len2=0;
        while(h1!=NULL){
            len1++;
            h1=h1->next;
        }
        while(h2!=NULL){
            len2++;
            h2=h2->next;
        }
        
        return len1-len2;
    }
    
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        int diff=getDiff(head1,head2);
        
        if(diff<0){
            while(diff<0){
                diff++;
                head2=head2->next;
            }
        }
        else{
            while(diff>0){
                diff--;
                head1=head1->next;
            }
        }
        
        while(head1!=NULL){
            if(head1==head2)
                return head1;
            
            head1=head1->next;
            head2=head2->next;
        }
        return NULL;
    }
};