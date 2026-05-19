class Solution:
    def rob(self, nums: List[int]) -> int:
        # given integer array

        # data processing
        """
        we can either rob a house or we can skip it and rob the next house
        dynamic programming
        - recurrence relation: dp[i] = max(dp[i-1], dp[i-2] + nums[i])
        """
        dp = [num for num in nums]
        if len(dp) < 2:
            return dp[0]
        dp[1] = max(dp[0], dp[1])

        for i in range(2, len(dp)):
            dp[i] = max(dp[i-1], dp[i-2] + nums[i])
        
        print(dp)

        # return max amount of money you can rob without alerting popo
        return max(dp[-1], dp[-2])