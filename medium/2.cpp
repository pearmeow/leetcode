/*
2. Add Two Numbers
Description of problem:
You are given two non-empty linked lists repheadenting two non-negative
integers. The digits are stored in reverse order, and each of their nodes
contains a single digit. Add the two numbers and return the sum as a linked
list. You may assume the two numbers do not contain any leading zero, except the
number 0 itself.
*/

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode* head = new ListNode();
  ListNode* newNum = head;
  int carry = 0;
  while (l1 || l2 || carry) {
    int total = 0;
    if (l1) {
      total += l1->val;
      l1 = l1->next;
    }
    if (l2) {
      total += l2->val;
      l2 = l2->next;
    }
    total += carry;
    carry = total / 10;
    newNum->next = new ListNode(total % 10);
    newNum = newNum->next;
  }
  ListNode* res = head->next;
  delete head;
  return res;
}

int main(int argc, char* argv[]) {
  ListNode numOne(1);
  ListNode numTwo(8);
  ListNode copy = numTwo;
  ListNode* next = &numTwo;
  for (int i = 0; i < 3; ++i) {
    next->next = new ListNode(9);
    next = next->next;
  }

  // next = &numTwo;
  // while (next != nullptr) {
  //     std::cout << next->val;
  //     next = next->next;
  // }
  // std::cout << std::endl;

  next = &numOne;
  for (int i = 0; i < 3; ++i) {
    next->next = new ListNode(9);
    next = next->next;
  }

  // next = &numOne;
  // while (next != nullptr) {
  //     std::cout << next->val;
  //     next = next->next;
  // }
  // std::cout << std::endl;

  ListNode* total = addTwoNumbers(&numOne, &numTwo);
  // std::cout << std::endl;
  while (total != nullptr) {
    std::cout << total->val;
    total = total->next;
  }
  std::cout << std::endl;
}