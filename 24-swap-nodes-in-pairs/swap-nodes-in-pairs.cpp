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
    void swapNodePairs(ListNode* node){
        if(node->next==nullptr)
            return;

        ListNode* nextNode = node;
        nextNode = nextNode->next;
        swap(node->val, nextNode->val);
        return;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr)
            return nullptr;

        ListNode* current = head;
        while(current != nullptr){
            swapNodePairs(current);
            current = current->next;
            if(current == nullptr){
                break;
            }
            else{
                current = current->next;
            }
        }

        return head;
    }
};