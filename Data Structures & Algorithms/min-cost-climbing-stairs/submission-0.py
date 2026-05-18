class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        # given array of integers
        # each cost[i] = cost of taking step from ith floor
        # after paying cost, can take 1 step or 2 steps
        # can start at index 0 or index 1

        """
        APPROACH
        - backtracking possible
        - 1D dp possible as well
            - dp[0], dp[1] = 0, 0
            - recurrence relation: for i > 1, dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2])
        """
        dp = [0 for i in range(len(cost)+1)]
        for i in range(2, len(cost)+1):
            dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2])

        # return minimum cost to reach top of staircase
        return dp[len(cost)]