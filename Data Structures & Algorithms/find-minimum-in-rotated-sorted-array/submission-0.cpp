/**
nums = [3,4,5,6,1,2] -> m=3 mid=6
mid > rig, so we know that the rotation happened on the right side of mid (exclusive)

[1,2] -> m=0 mid=1


nums = [4,5,0,1,2,3]
m=3 mid=1
mid < right, so we know that the rotation happened on the left side of mid (inclusive)

[4,5,0,1] -> m=2, mid=0
mid < right, so rotation happened on left side

[4,5,0]

*/


class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0, r=nums.size()-1;

        while (l <= r) {
            if (r - l <= 2) {
                auto min_int = min_element(nums.begin()+l, nums.begin()+r+1);
                return *min_int;
            }

            int m = l + (r - l)/2;
            
            int lef = nums[l];
            int rig = nums[r];
            int mid = nums[m];

            // case 1: mid is bigger than right
            if (mid > rig) {
                l = m+1;
            } else {
                r = m;
            }
        }
        
        return -1;
    }
};
