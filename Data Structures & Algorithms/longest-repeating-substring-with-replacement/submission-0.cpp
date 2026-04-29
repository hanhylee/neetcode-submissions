class Solution {
public:
    int characterReplacement(string s, int k) {
        /**
        dynamic sliding window solution
        - keep a frequency count of all elements sorted from highest frequency to lowest
        - we can then calculate the count of all elements - highest frequency to get the max k
        - if this difference > k, then we have to increment the left edge and decrement its freq
        */
        if (s.size() < 2) return s.size();

        int l=0, r=1;
        unordered_map<char, int> freq = {{s[l], 1}};
        if (freq.find(s[r]) == freq.end()) {
            freq[s[r]] = 1;
        } else {
            freq[s[r]]++;
        }
        int max_len=1;

        while (r < s.size()) {
            // get highest freq and total count
            int max_freq = 0;
            int count = 0;
            for (const auto& kv: freq) {
                max_freq = max(max_freq, kv.second);
                count += kv.second;
            }

            if (count - max_freq > k) {
                cout << "count - max_freq > k" << "\n";
                freq[s[l]]--;
                l++;
                continue;
            } else {
                cout << "count: " << count << ". ";
                cout << "max_freq: " << max_freq << "\n";
                max_len = max(max_len, r-l+1);
            }

            r++;
            if (freq.find(s[r]) == freq.end()) {
                freq[s[r]] = 1;
            } else {
                freq[s[r]]++;
            }
        }

        return max_len;
    }
};
