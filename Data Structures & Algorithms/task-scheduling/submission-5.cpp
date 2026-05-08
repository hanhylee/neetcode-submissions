class Solution {
public:
    unordered_map<char, int> countFreq(vector<char>& tasks) {
        unordered_map<char, int> freq;
        for (char task: tasks) {
            if (freq.find(task) == freq.end()) {
                freq[task] = 1;
            } else {
                freq[task]++;
            }
        }
        return freq;
    }

    struct FreqTask {
        int freq;
        char task;
        int cooldown;

        FreqTask(int freq, char task) {
            this->freq = freq;
            this->task = task;
            this->cooldown = 0;
        }

        bool operator<(const FreqTask other) const {
            return freq < other.freq;
        }
    };

    vector<FreqTask> mapToArray(unordered_map<char, int> freq) {
        vector<FreqTask> freq_array;

        for (const auto& kv: freq) {
            FreqTask newFreqTask(kv.second, kv.first);
            freq_array.push_back(newFreqTask);
        }

        return freq_array;
    }

    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq = countFreq(tasks);
        vector<FreqTask> freq_array = mapToArray(freq);
        priority_queue<FreqTask, vector<FreqTask>, less<FreqTask>> max_heap(freq_array.begin(), freq_array.end());
        queue<FreqTask> q;

        int curr_time = 0;

        while (!max_heap.empty() || !q.empty()) {
            while (q.size() <= n && !max_heap.empty()) {
                q.push(max_heap.top());
                max_heap.pop();
            }
            curr_time++;
            FreqTask nextTask = q.front();
            q.pop();
            if (nextTask.cooldown <= curr_time) {
                nextTask.cooldown = curr_time + n + 1;
                nextTask.freq--;
                cout << "done task " << nextTask.task << ". new freq: " << nextTask.freq << "\n";
                if (nextTask.freq > 0) {
                    max_heap.push(nextTask);
                }
            } else {
                while (nextTask.cooldown > curr_time) {
                    curr_time++;
                    cout << "advanced time\n";
                }
                nextTask.cooldown = curr_time + n + 1;
                nextTask.freq--;
                cout << "done task " << nextTask.task << ". new freq: " << nextTask.freq << "\n";
                if (nextTask.freq > 0) {
                    max_heap.push(nextTask);
                }
            }
        }

        return curr_time;
    }
};
