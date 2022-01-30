class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> stack;
    vector<int> minStack;
    MinStack() {
        this -> stack = {};
        this -> minStack = {};
    }
    
    void push(int val) {
        stack.push_back(val);
        
        if (minStack.size() != 0) {
            int lastEle = minStack[minStack.size() - 1];
            if (val < lastEle)
                minStack.push_back(val);
            else
                minStack.push_back(lastEle);
        } else {
            minStack.push_back(val);
        }
    }
    
    void pop() {
        stack.pop_back();
        minStack.pop_back();
    }
    
    int top() {
        return stack[stack.size() - 1];
    }
    
    int getMin() {
        return minStack[minStack.size() - 1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
