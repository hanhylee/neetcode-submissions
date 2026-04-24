class Solution {
public:
    
    string encode(vector<string>& strs) {
        string encoded_s;

        for (const string& s: strs) {
            string len = to_string(s.size());
            for (const char& c: len) {
                encoded_s.push_back(c);
            }
            encoded_s.push_back('#');
            for (const char& c: s) {
                encoded_s.push_back(c);
            }
        }

        cout << encoded_s << endl;
        return encoded_s;
    }

    vector<string> decode(string s) {
        int i = 0;
        int len = s.size();
        vector<string> strs;
        int delimiter_start_idx = i;
        int delimiter_end_idx = i+1;

        while (i < len) {
            if (s[i] != '#') {
                delimiter_end_idx++;
            } else {
                int curr_len = stoi(s.substr(delimiter_start_idx, delimiter_end_idx));
                string curr_str = s.substr(delimiter_end_idx, curr_len);
                strs.push_back(curr_str);
                i += curr_len;
                delimiter_start_idx = i+1;
                delimiter_end_idx = i+2;
            }
            i++;
        }

        return strs;
    }
};
