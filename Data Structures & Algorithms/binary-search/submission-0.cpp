/**
nums = [-1,0,2,4,6,8], target = 2
m = 3 -> r = 2
m = 1 -> l = 2

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;

        while (l < r) {
            int m = (r+l)/2;

            if (target == nums[m]) {
                return m;
            } else if (target < nums[m]) {
                r = m-1;
            } else {
                l = m+1;
            }
        }

        if (target == nums[l]) return l;
        if (target == nums[r]) return r;

        return -1;
    }
};
