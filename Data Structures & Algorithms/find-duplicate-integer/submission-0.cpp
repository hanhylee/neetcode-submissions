/**
nums = [1,2,3,2,2]
1 <= n <= 10,000

each integer appears ONCE -> return integer that appears more than once

brute force: compare each number to the other and return number if they match


*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            for (int j=i+1; j<nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    return nums[i];
                }
            }
        }
        return -1;
    }
};
