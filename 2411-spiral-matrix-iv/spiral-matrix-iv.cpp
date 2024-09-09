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
        // Store the right, down, left, up movements in a matrix.
        int i = 0, j = 0, choice = 0;
        int movement[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> res(m, vector<int>(n, -1));

        for (; head != nullptr; head = head->next) {
            res[i][j] = head->val;
            int newi = i + movement[choice][0]; 
            int newj = j + movement[choice][1];
            
            // If we bump into an edge or an already filled cell, change the
            // direction.
            
            if (min(newi, newj) < 0 || newi >= m || newj >= n || res[newi][newj] != -1){
                choice = (choice + 1) % 4;
            }
            i += movement[choice][0];
            j += movement[choice][1];
        }

        return res;
    }
};