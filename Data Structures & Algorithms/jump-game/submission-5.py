class Solution:
    def canJump(self, nums: List[int]) -> bool:
        # INPUT: list of max jump lengths

        """
        APPROACH:
        - since we're choosing to jump or not at each step, we can use dynamic programming
        - each element in the dp array is a boolean of whether we can access that location
        - we set the base case dp[0] as 1
        """

        i = 0
        while i < len(nums) and nums[i] != 0:
            # termination
            if i + nums[i] >= len(nums) - 1:
                return True

            # greedy. go to the next idx with furthest range
            max_idx = i+1

            for j in range(i+1, i+nums[i]+1):
                max_idx = j if j + nums[j] > nums[max_idx] + max_idx else max_idx

            if nums[max_idx] > 0:
                i = max_idx
            else:
                return False

        # OUTPUT: true if last index can be reached from idx 0
        return True if len(nums) == 1 else False
