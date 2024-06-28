/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
        int n1=0, n2=0;
        for(ListNode* i=headA; i!=NULL; i=i->next){
            n1++;
        }
        for(ListNode* i=headB; i!=NULL; i=i->next){
            n2++;
        }

        int diff=0;

        if(n1>n2){
            diff=n1-n2;
            for(int i=0;i<diff;i++){
                headA=headA->next;
            }
        }
        else{
            diff=n2-n1;
            for(int i=0;i<diff;i++){
                headB=headB->next;
            }
        }

        ListNode* temp1=headA;
        ListNode* temp2=headB;
        
        while(temp1!=NULL && temp2!=NULL){
            if(temp1==temp2){
                return temp1;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;
    }
};