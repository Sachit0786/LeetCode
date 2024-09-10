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
    int gcd_of_2_numbers(int a, int b)
    {
        // Everything divides 0
        if (a == 0)
            return b;
        if (b == 0)
            return a;

        // Base case
        if (a == b)
            return a;

        // a is greater
        if (a > b) {
            if (a % b == 0)
                return b;
            return gcd(a - b, b);
        }
        if (b % a == 0)
            return a;
        return gcd(a, b - a);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;

        ListNode* current = head;
        ListNode* next_node = head->next;
        while(next_node != nullptr){
            int gcd = gcd_of_2_numbers(current->val, next_node->val);
            ListNode* node = new ListNode(gcd);
            current->next = node;
            node->next = next_node;
            current = next_node;
            next_node = next_node->next;
        } 
        return head;            
    }
};