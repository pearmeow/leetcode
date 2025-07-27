/**
 * @file 2-add-two-numbers.cpp
 * @author Perry Huang
 * @date 2024-10-12
 * 2. Add Two Numbers
 * You are given two non-empty linked lists repheadenting two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list. You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 */

class Solution {
   public:
    // Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode;
        ListNode* curr = dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int val = carry;
            carry = 0;
            if (l1) {
                val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                val += l2->val;
                l2 = l2->next;
            }
            if (val > 9) {
                val = val % 10;
                carry = 1;
            }
            curr->next = new ListNode(val);
            curr = curr->next;
        }
        ListNode* res = dummy;
        res = res->next;
        delete dummy;
        return res;
    }
};
