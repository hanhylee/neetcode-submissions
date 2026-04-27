class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string substring = "";
        unordered_set<char> substring_chars;
        int max_len = 0;

        for (const char& c: s) {
            if (substring.find(c) == -1) {
                // substring_chars.insert(c);
                substring.push_back(c);
                max_len = max(max_len, (int) substring.size());
            } else {
                while (substring.size() > 0 && substring.find(c) != -1) {
                    cout << substring.find(c) << endl;
                    // substring_chars.erase(substring[0]);
                    substring.erase(0, 1);
                }
                // substring_chars.insert(c);
                substring.push_back(c);
            }
            cout << substring << endl;
        }

        return max_len;
    }
};
