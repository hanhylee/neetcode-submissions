#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    bool checkMatch(unordered_map<char, int>& t_freq, unordered_map<char, int>& s_freq) {
        for (const auto& kv: t_freq) {
            if (s_freq.find(kv.first) == s_freq.end()) {
                return false;
            } else if (kv.second > s_freq[kv.first]) {
                return false;
            }
        }
        return true;
    }

    unordered_map<char, int> countFreq(string& s, int l, int window_size) {
        unordered_map<char, int> freq;
        for (int i=l; i<l+window_size; i++) {
            addFreq(freq, s[i]);
        }
        return freq;
    }

    void addFreq(unordered_map<char, int>& freq, char& c) {
        if (freq.find(c) == freq.end()) freq[c] = 1;
        else freq[c]++;
    }

    void removeFreq(unordered_map<char, int>& freq, char& c) {
        freq[c]--;
        if (freq[c] == 0) freq.erase(c);
    }

    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        if (t.size() == 0) return "";
        if (s.size() == 1) return s[0] == t[0] ? s : "";

        int l=0, r=0;
        unordered_map<char, int> t_freq = countFreq(t, 0, t.size());
        unordered_map<char, int> substr_freq = {{s[0], 1}};
        string min_substr = "";

        while (r<s.size()) {
            while (r<s.size() && !checkMatch(t_freq, substr_freq)) {
                r++;
                addFreq(substr_freq, s[r]);
            }
            cout << "r: " << r << "\n";
            while (checkMatch(t_freq, substr_freq)) {
                if (min_substr == "") {
                    min_substr = s.substr(l, r-l+1);
                } else {
                    min_substr = r-l+1 < min_substr.size() ? s.substr(l, r-l+1) : min_substr;
                }
                removeFreq(substr_freq, s[l]);
                l++;
            }
        }

        return min_substr;
    }
};
