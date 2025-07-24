#include <iostream>
#include <stack>

class MinStack {
public:
    std::stack<int> stack;
    std::stack<int> minStack;

    void push(int val) {
        this->stack.push(val);

        if (this->minStack.empty()) {
            this->minStack.push(val);
        } else if (val < this->minStack.top()) {
            this->minStack.push(val);
        } else {
            this->minStack.push(this->minStack.top());
        }
    }

    void pop() {
        this->stack.pop();
        this->minStack.pop();
    }

    int top() {
        return this->stack.top();
    }

    int getMin() {
        return this->minStack.top();
    }
};

int main() {
    MinStack minStack;

    minStack.push(1);
    minStack.push(2);
    minStack.push(0);

    std::cout << minStack.getMin() << "\n";
    minStack.pop();
    std::cout << minStack.top() << "\n";
    std::cout << minStack.getMin() << "\n";
}

/*
Example 1:

Input: ["MinStack", "push", 1, "push", 2, "push", 0, "getMin", "pop", "top", "getMin"]

Output: [null,null,null,null,0,null,2,1]
*/
