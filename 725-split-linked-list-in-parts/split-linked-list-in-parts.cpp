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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        if(head==nullptr){
            vector<ListNode*> ans(k,nullptr);
            return ans;
        }

        int number_of_nodes = 0;
        ListNode* current = head;
        while(current != nullptr){
            number_of_nodes++;
            current = current->next;
        }
        vector<int> reference(k,(number_of_nodes/k));
        int remaining = number_of_nodes % k;
        int i=0;
        while(remaining != 0){
            reference[i]++;
            remaining--;
            i++; 
        }
        vector<ListNode*> ans(k,nullptr);
        current = head;
        for(int i=0; i<k; i++){
            ListNode* temp;
            int count = 0;
            ans[i] = current;
            while(count != reference[i]){
                temp = current;
                current = current->next;
                count++;
            }
            temp->next = nullptr;
            cout<<reference[i];
        }
        return ans;
    }
};