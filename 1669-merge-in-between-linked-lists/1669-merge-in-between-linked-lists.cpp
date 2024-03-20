class Solution {
public:
  ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    if (list1 == nullptr) {
      return list2;
    }
    if (list2 == nullptr) {
      return list1;
    }

    ListNode* temp = list1;
    int cnt = 0;

    while (temp != nullptr && cnt < a-1) {
      temp = temp->next;
      cnt++;
    }

    while (cnt < b && temp->next != nullptr) {
      temp->next = temp->next->next;
      cnt++;
    }
    ListNode* next = temp->next;
    
    temp->next = list2;
    while (list2->next != nullptr) {
      list2 = list2->next;
    }
    list2->next = next;

    return list1;
  }
};