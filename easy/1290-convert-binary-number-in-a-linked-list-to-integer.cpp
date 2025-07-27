/**
 * @file 1290-convert-binary-number-in-a-linked-list-to-integer.cpp
 * @author Perry Huang
 * @date 2025-07-13
 * 1290. Convert Binary Number in a Linked List to Integer
 * Given head which is a reference node to a singly-linked list. The value of each node in the linked list is
 * either 0 or 1. The linked list holds the binary representation of a number. Return the decimal value of the
 * number in the linked list. The most significant bit is at the head of the linked list.
 */

class Solution {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };

    int getDecimalValue(ListNode* head) {
        int res = 0;
        while (head != nullptr) {
            res = (res << 1) | head->val;
            head = head->next;
        }
        return res;
    }
};
