class Solution:
    def rob(self, nums: List[int]) -> int:
        # given list of int
        # houses are arranged in circle

        # CONSTRAINT: cannot rob two adjacent houses

        # data processing
        """
        1d dp array
        dp[0] = max(dp[-1], dp[-2]+nums[0])
        dp[1] = max(dp[0], dp[-1]+nums[1])
        dp[i] = max(dp[i-1], dp[i-2]+nums[i]), i >= 2
        """
        if len(nums) == 1:
            return nums[0]
        if len(nums) == 2:
            return max(nums[0], nums[1])

        dp0 = [num for num in nums]
        dp0[1] = max(nums[0], nums[1])
        dp1 = [num for num in nums]
        dp1[0] = 0
        for i in range(2, len(nums)-1):
            dp0[i] = max(dp0[i-1], dp0[i-2]+nums[i])
            dp1[i] = max(dp1[i-1], dp1[i-2]+nums[i])
        
        dp0[-1] = max(dp0[-2], dp0[-3]+nums[-1]-nums[0])
        dp1[-1] = max(dp1[-2], dp1[-3]+nums[-1])
        return max(dp0[-1], dp1[-1])

        # return max money you can rob without alerting police