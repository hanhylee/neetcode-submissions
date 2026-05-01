/**
nums = [3,4,5,6,1,2], target = 6
m=2 -> mid=5
l=0 -> lef=3
r=5 -> rig=2

if lef < target < mid, then we know target is between lef and mid
if lef > target and target < mid, then we know target is to the right side of mid
if mid < target < rig, then we know target is between mid and rig
if mid < target and target > rig, then we know target is to the left of mid

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        int rotation_idx = -1;

        while (l <= r) {
            int m = l + (r - l)/2;

            int mid = nums[m];
            int rig = nums[r];
            int lef = nums[l];
            cout << l << " " << m << " " << r << "\n";

            if (target == mid) return m;
            if (target == lef) return l;
            if (target == rig) return r;

            // case 1: right side is sorted
            if (mid < rig) {
                if (target > mid && target < rig) {
                    r--;
                    l = m+1;
                } else {
                    l++;
                    r = m-1;
                }
            } 
            // case 2: left side is sorted
            else {
                if (target < mid && target > lef) {
                    l++;
                    r = m-1;
                } else {
                    r--;
                    l = m+1;
                }
            }
        }

        return -1;
    }
};
