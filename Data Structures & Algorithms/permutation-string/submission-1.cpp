#include <string>
#include <algorithm>

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int window_size = s1.size();
        cout << window_size<< "\n";

        if (s2.size() < window_size) return false;

        // sort s1
        sort(s1.begin(), s1.end());

        for (int i=window_size; i<s2.size()+1; i++) {
            string search_window = s2.substr(i-window_size, window_size);
            cout << search_window << "\n";
            sort(search_window.begin(), search_window.end());
            if (search_window == s1) return true;
        }
        return false;
    }
};
