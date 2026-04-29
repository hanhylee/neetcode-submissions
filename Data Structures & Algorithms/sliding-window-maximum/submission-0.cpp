/**
return a list that returns the maximum element in the window at each step
brute force: calculate max value for each window -> O(n * k)

*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int r = k-1;
        vector<int> res;
        while (r < nums.size()) {
            auto it = max_element(nums.begin()+r-k+1, nums.begin()+r+1);
            res.push_back(*it);
            r++;
        }
        return res;
    }
};
