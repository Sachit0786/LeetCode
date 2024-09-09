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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int i = 0, j = 0;
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        
        while (head != nullptr) {
            ans[i][j] = head->val;
            head = head->next;

            // Move right
            if (i == top && j < right) {
                j++;
                if (j == right) top++;
            }
            // Move down
            else if (j == right && i < bottom) {
                i++;
                if (i == bottom) right--;
            }
            // Move left
            else if (i == bottom && j > left) {
                j--;
                if (j == left) bottom--;
            }
            // Move up
            else if (j == left && i > top) {
                i--;
                if (i == top) left++;
            }
        }

        return ans;
    }
};
