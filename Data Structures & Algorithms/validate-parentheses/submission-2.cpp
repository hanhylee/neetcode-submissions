#include <vector>

class Solution {
public:
    bool isValid(string s) {
        vector<char> char_stack;
        unordered_map<char, char> valid_close = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (const char& c: s) {
            if (valid_close.find(c) == valid_close.end()) {
                char_stack.push_back(c);
            } else {
                if (char_stack.empty()) return false;
                char opener = char_stack.back();
                char_stack.pop_back();
                if (opener != valid_close[c]) return false;
            }
        }
        return char_stack.empty() ? true : false;
    }
};
