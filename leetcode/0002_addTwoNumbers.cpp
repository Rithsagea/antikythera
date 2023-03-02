#include "base.hpp"

//https://leetcode.com/problems/add-two-numbers/

struct ListNode {
  int val;
  ListNode* next;
  ListNode(): val(0), next(nullptr) {}
  ListNode(int x): val(x), next(nullptr) {}
  ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode sentinel(0), * p = &sentinel;
    
    while (l1 || l2 || (sentinel.val /= 10)) {
      if (l1) sentinel.val += l1->val, l1 = l1->next;
      if (l2) sentinel.val += l2->val, l2 = l2->next;
      p = (p->next = new ListNode(sentinel.val % 10));
    }

    return sentinel.next;
  }
};