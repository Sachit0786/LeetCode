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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==nullptr)
            return nullptr;

        ListNode* current = head;    
        ListNode* firstNumber;            
        int count = 0;
        while(current != nullptr){
            count++;
            if(count==k)
                firstNumber = current;

            current = current->next;
        }
        current = head;
        int temp = 1;
        while(temp != count-k+1){
            temp++;
            current = current->next;
        }
        swap(current->val, firstNumber->val);
        return head;
    }
};