class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (const auto& num: nums) {
            if (freq.find(num) == freq.end()) {
                freq[num] = 1;
            } else {
                freq[num]++;
            }
        }

        priority_queue<pair<int, int>> max_priority_queue;
        for (const auto& kv: freq) {
            max_priority_queue.push(pair<int,int>(kv.second, kv.first));
            cout << "value: " << kv.first << ". freq: " << kv.second << endl;
        }

        vector<int> ret;
        for (int i=0; i<k; i++) {
            ret.push_back(max_priority_queue.top().second);
            max_priority_queue.pop();
        }

        return ret;
    }
};
