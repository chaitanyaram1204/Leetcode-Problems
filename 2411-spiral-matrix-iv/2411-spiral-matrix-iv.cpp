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

        vector<vector<int>> matrix(m, vector<int>(n, -1));
        int r = 0;
        int er = m - 1;
        int c = 0;
        int ec = n - 1;
        while (head) {
            for (int column = c; column <= ec && head; column++) {
                matrix[r][column] = head->val;
                head = head->next;
            }
            r++;

            for (int row = r; row <= er && head; row++) {
                matrix[row][ec] = head->val;
                head = head->next;
            }
            ec--;

            for (int column = ec; column >= c && head; column--) {
                matrix[er][column] = head->val;
                head = head->next;
            }
            er--;

            for (int row = er; row >= r && head; row--) {
                matrix[row][c] = head->val;
                head = head->next;
            }
            c++;
        }
        return matrix;
    }
};