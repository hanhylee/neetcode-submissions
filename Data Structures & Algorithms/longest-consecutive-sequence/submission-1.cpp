class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();

        unordered_map<int,int> nummap;
        for (int i=0; i<nums.size(); i++) {
            nummap[nums[i]] = -1;
        }

        int global_max = 1;
        for (int i=0; i<nums.size(); i++) {
            // if we've processed this num before, stop
            if (nummap[nums[i]] != -1) continue;

            int local_max = 1;
            int next = nums[i]+1;
            while (nummap.find(next) != nummap.end()) {
                if (nummap[next] > 0) {
                    local_max += nummap[next];
                    break;
                }
                local_max++;
                next++;
            }
            nummap[nums[i]] = local_max;
            global_max = max(global_max, local_max);
        }

        return global_max;
    }
};
