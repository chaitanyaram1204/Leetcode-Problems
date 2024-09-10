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
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        vector<int> gcds;
        ListNode* temp = head;

        while (temp && temp->next) {
            int first = temp->val;
            temp = temp->next;
            int second = temp->val;
            gcds.push_back(gcd(first,second));
        }

        temp = head;
        int i = 0;
        int n = gcds.size();
        //temp = temp -> next;
        while(i < n && temp){
            ListNode* next = temp -> next;
            temp->next = new ListNode(gcds[i++]);
            temp->next->next = next;
            temp = temp->next->next;
        }
        return head;
    }
};