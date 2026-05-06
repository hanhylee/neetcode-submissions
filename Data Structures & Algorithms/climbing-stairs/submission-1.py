class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [1, 1]

        # recurrence relation: dp[i] = dp[i-1] + dp[i-2]
        # [1,2,3]

        for i in range(2, n+1, 1):
            dp.append(dp[i-1] + dp[i-2])

        return dp[n];