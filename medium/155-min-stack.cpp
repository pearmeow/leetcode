/**
 * @file 155-min-stack.cpp
 * @author Perry Huang
 * @date 2025-07-27
 * 155. Min Stack
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * Implement the MinStack class:
 * MinStack() initializes the stack object.
 * void push(int val) pushes the element val onto the stack.
 * void pop() removes the element on the top of the stack.
 * int top() gets the top element of the stack.
 * int getMin() retrieves the minimum element in the stack.
 * You must implement a solution with O(1) time complexity for each function.
 */

#include <utility>
#include <vector>

// pop, top, and getMin will never be called on empty stack
class MinStack {
   public:
    MinStack() {}

    void push(int val) {
        int theMin = val;
        if (theStack.size() != 0) {
            theMin = std::min(theMin, theStack[theStack.size() - 1].second);
        }
        theStack.push_back({val, theMin});
    }

    void pop() {
        theStack.pop_back();
    }

    int top() {
        return theStack[theStack.size() - 1].first;
    }

    int getMin() {
        return theStack[theStack.size() - 1].second;
    }

   private:
    std::vector<std::pair<int, int>> theStack;
};
