/*
@file: 21.cpp
@author: Perry Huang
@date: 3/3/2024

21. Merge Two Sorted Lists
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing
together the nodes of the first two lists.

Return the head of the merged linked list.
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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  if (!list1) return list2;
  if (!list2) return list1;
  ListNode* head;
  if (list1->val <= list2->val) {
    head = list1;
    list1 = list1->next;
  } else {
    head = list2;
    list2 = list2->next;
  }
  ListNode* curr = head;
  while (list1 && list2) {
    if (list1->val <= list2->val) {
      curr->next = list1;
      list1 = list1->next;
      curr = curr->next;
    } else {
      curr->next = list2;
      list2 = list2->next;
      curr = curr->next;
    }
  }
  if (!list1) curr->next = list2;
  if (!list2) curr->next = list1;
  return head;
}

int main() {
  //[1, 2, 4] [1, 3, 4]
}