#include <vector>

class MinStack {
public:
    vector<int> *int_stack;
    int min_val;

    MinStack() {
        int_stack = new vector<int>();
        min_val = INT_MAX;
    }
    
    void push(int val) {
        int_stack->push_back(val);
        min_val = min(min_val, val);
    }
    
    void pop() {
        int back = int_stack->back();
        int_stack->pop_back();
        if (min_val == back) {
            min_val = INT_MAX;
            for (const auto& num: *int_stack) {
                min_val = min(min_val, num);
            }
        }
    }
    
    int top() {
        return int_stack->back();
    }
    
    int getMin() {
        return min_val;
    }
};
