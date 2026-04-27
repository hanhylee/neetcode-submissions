class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> triplets;
        int i = 0;
        while (i<nums.size()) {
            int curr = nums[i];
            int target = 0 - curr;
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (nums[r] + nums[l] == target) {
                    triplets.push_back({nums[i], nums[l], nums[r]});
                    int curr_l = nums[l];
                    int curr_r = nums[r];
                    while (nums[l] == curr_l) {
                        l++;
                    }
                    while (nums[r] == curr_r) {
                        r--;
                    }
                } else if (nums[r] + nums[l] > target) {
                    r--;
                } else {
                    l++;
                }
            }
            while (nums[i] == curr) {
                i++;
            }
        }
        return triplets;
    }
};
