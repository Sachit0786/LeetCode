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
        unordered_map<ListNode*,int> mp;

        for(ListNode* temp=headA; temp!=NULL; temp = temp->next){
            mp[temp] = temp->val;
        }

        for(ListNode* temp=headB; temp!=NULL; temp = temp->next){
            if(mp.find(temp) != mp.end()){
                return temp;
            }
        }
        return nullptr;
    }
};