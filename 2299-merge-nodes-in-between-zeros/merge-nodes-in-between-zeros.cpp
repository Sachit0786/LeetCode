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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = new ListNode(0);
        ListNode* ans = temp;
        head = head->next;
        while(head!=nullptr){
            if(head->val==0){
                if(head->next==nullptr){
                    return ans;
                }
                temp->next = new ListNode(0);
                temp = temp->next;     
            }
            else{
                temp->val = temp->val + head->val;
            }
            head = head->next;
        }
        return nullptr;
    }
};