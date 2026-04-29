/**
return a list that returns the maximum element in the window at each step
brute force: calculate max value for each window -> O(n * k)
optimized:
[1,2,1,0,4,2,6]
[1,2,2,]
frequencies at each point. if freq drops to 0 when sliding window and that was the maximum, max is the next highest freq
*/

class Solution {
public:
    void addFreq(unordered_map<int, int>& freq, int x) {
        if (freq.find(x) == freq.end()) {
            freq[x] = 1;
        } else {
            freq[x]++;
        }
    }

    bool removeFreq(unordered_map<int, int>& freq, int x, int curr_max) {
        freq[x]--;
        if (freq[x] == 0) {
            freq.erase(x);
        }
        if (x == curr_max) {
            return true;
        }
        return false;
    }

    int getNewMax(unordered_map<int, int>& freq) {
        int new_max = -10001;
        for (const auto& kv: freq) {
            new_max = max(new_max, kv.first);
        }
        return new_max;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int first_max = -10001;
        for (int i=0; i<k; i++) {
            first_max = max(first_max, nums[i]);
            addFreq(freq, nums[i]);
        }
        vector<int> res = {first_max};

        int r = k;
        while (r < nums.size()) {
            addFreq(freq, nums[r]);

            int l = r - k;
            bool need_new_max = removeFreq(freq, nums[l], res.back());
            if (need_new_max) {
                cout << "need new max" << "\n";
                int new_max = getNewMax(freq);
                res.push_back(max(new_max, nums[r]));
            } else {
                cout << "appending " << max(res.back(), nums[r]) << "\n";
                res.push_back(max(res.back(), nums[r]));
            }

            r++;
        }

        // while (r < nums.size()) {
        //     auto it = max_element(nums.begin()+r-k+1, nums.begin()+r+1);
        //     res.push_back(*it);
        //     r++;
        // }
        return res;
    }
};
