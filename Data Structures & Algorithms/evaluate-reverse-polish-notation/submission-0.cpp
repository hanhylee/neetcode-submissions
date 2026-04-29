#include <vector>
#include <string>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> int_stack;

        for (const auto& token: tokens) {
            if (token == "+") {
                int b = int_stack.back();
                int_stack.pop_back();
                int a = int_stack.back();
                int_stack.pop_back();
                int_stack.push_back(a+b);
            } else if (token == "-") {
                int b = int_stack.back();
                int_stack.pop_back();
                int a = int_stack.back();
                int_stack.pop_back();
                int_stack.push_back(a-b);
            } else if (token == "*") {
                int b = int_stack.back();
                int_stack.pop_back();
                int a = int_stack.back();
                int_stack.pop_back();
                int_stack.push_back(a*b);
            } else if (token == "/") {
                int b = int_stack.back();
                int_stack.pop_back();
                int a = int_stack.back();
                int_stack.pop_back();
                int_stack.push_back(a/b);
            } else {
                int_stack.push_back(stoi(token));
            }
        }

        return int_stack.back();
    }
};
