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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* slowBack = nullptr;
        
        while(fast && fast->next){
            slowBack = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(slowBack==nullptr)
            return nullptr;

        slowBack->next=slow->next;

        slow->next = nullptr;
        delete slow;

        return head;

    }
};