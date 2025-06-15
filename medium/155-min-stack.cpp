#include <vector>
#include <utility>

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
