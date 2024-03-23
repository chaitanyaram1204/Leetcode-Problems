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
    void reorderList(ListNode* head) {
        if(!head || !head->next)
        return;
        stack<ListNode*>st;
        int cnt = 1;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next)
        {
            cnt++;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        int i = 0;
        ListNode* temp = head;
        while(i<cnt && temp)
        {
            st.push(temp);
            temp = temp->next;
            i++;
        }
        //cout<<slow->val;
        slow->next = NULL;
        if(!fast)
        {
                st.pop();
        }
        //cout<<cnt<<endl;
        while(temp && !st.empty())
        {

            ListNode* top = st.top();
            ListNode* next = top->next;
            top->next = temp;
            temp = temp->next;
            top->next->next = next;
            st.pop();
        }

    }
};