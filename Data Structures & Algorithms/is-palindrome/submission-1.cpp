class Solution {
public:
    bool isPalindrome(string s) {
        unordered_set<char> valid = {
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
            'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
            'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
            'Y', 'Z', '1', '2', '3', '4', '5', '6',
            '7', '8', '9', 'a', 'b', 'c', 'd', 'e',
            'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
            'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
            'v', 'w', 'x', 'y', 'z', '0'
        };
        unordered_map<char,char> uppertolower = {
            {'A', 'a'}, {'B', 'b'}, {'C', 'c'}, {'D', 'd'},
            {'E', 'e'}, {'F', 'f'}, {'G', 'g'}, {'H', 'h'},
            {'I', 'i'}, {'J', 'j'}, {'K', 'k'}, {'L', 'l'},
            {'M', 'm'}, {'N', 'n'}, {'O', 'o'}, {'P', 'p'},
            {'Q', 'q'}, {'R', 'r'}, {'S', 's'}, {'T', 't'},
            {'U', 'u'}, {'V', 'v'}, {'W', 'w'}, {'X', 'x'},
            {'Y', 'y'}, {'Z', 'z'}
        };
        string clean_s;
        for (const char& c: s) {
            if (valid.find(c) != valid.end()) {
                char x;
                if (uppertolower.find(c) != uppertolower.end()) {
                    x = uppertolower[c];
                } else {
                    x = c;
                }
                clean_s.push_back(x);
            }
        }

        cout << clean_s << endl;

        int len = clean_s.size();
        int mid = len/2;
        int offset = 0;
        if (len % 2 == 0) {
            while (offset <= mid - 1) {
                if (clean_s[mid-offset-1] != clean_s[mid+offset]) return false;
                offset++;
            }
        } else {
            while (offset <= mid) {
                if (clean_s[mid-offset] != clean_s[mid+offset]) return false;
                offset++;
            }
        }
        return true;
    }
};
