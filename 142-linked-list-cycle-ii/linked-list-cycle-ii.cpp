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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr)
            return nullptr;
        
        unordered_set<ListNode*> st;
        ListNode* curr = head;

        while(curr->next != nullptr){
            st.insert(curr);
            if(st.find(curr->next) != st.end()){
                return curr->next;
            }
            curr = curr->next;
        }
        return nullptr;
    }
};