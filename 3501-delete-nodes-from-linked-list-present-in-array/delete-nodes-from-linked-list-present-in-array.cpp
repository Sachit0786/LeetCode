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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(head==nullptr){
            return nullptr;
        }

        unordered_set<int> array_values(nums.begin(), nums.end());

        while (head != nullptr && array_values.count(head->val) > 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        ListNode* current = head;
        //here we make sure that current is not present in the array
        while(current->next != nullptr){
            if(array_values.contains(current->next->val)){
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }   
            // to make sure that current is not present in the array we cannot here move to
            // "current = current->next" before checking the value of current->next so we
            // again go in the loop to check the next value
            else{
                current = current->next;
            }
        }

        return head;
    }
};