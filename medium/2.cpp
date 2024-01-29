/*
2. Add Two Numbers
Description of problem:
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/


// Definition for singly-linked list.

#include <iostream>

struct ListNode;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode res;
    int carry = 0;
    return &res;
}

int main(int argc, char* argv[]) {
    ListNode test(1);
    ListNode other(9);
    return 0;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};