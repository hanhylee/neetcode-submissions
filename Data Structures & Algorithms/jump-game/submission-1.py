class Solution:
    def canJump(self, nums: List[int]) -> bool:
        # INPUT: list of max jump lengths

        """
        APPROACH:
        - since we're choosing to jump or not at each step, we can use dynamic programming
        - each element in the dp array is a boolean of whether we can access that location
        - we set the base case dp[0] as 1
        """

        dp = [0 for x in nums]
        dp[0] = 1

        for i in range(len(nums)):
            if dp[i]:
                for j in range(nums[i]):
                    if i+j+1 < len(nums):
                        dp[i+j+1] = 1

        print(dp)
        # OUTPUT: true if last index can be reached from idx 0
        return True if dp[-1] else False
