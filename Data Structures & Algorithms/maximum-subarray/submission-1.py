class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        #INPUT: list of integers

        """
        BRUTE FORCE:
        - dynamic sliding window starting from the widest window all the way to the smallest
        - calculate the sum of elements in the window -> return the max
        - O(n^3)

        DYNAMIC PROGRAMMING:
        - calculate sums in a 2D array where each column represents the maximum sum when the row'th element is added
           |    2    -3     4    -2   2   1   -1   4
        -----------------------------------------------
         0 |    2    -3     4    -2   2   1   -1   4
         1 |         -1     1     2   0   3   0    3
         2 |                3     -1  4   1   2    4
         3 |                      
           |
           |
        - recurrence relation: dp[r][c] = dp[0][c] + dp[r-1][c-1]
        - update max_sum as dp gets built
        - O(n^2)
        """

        dp = [[x for x in nums] for y in nums]
        max_sum = max(nums)
        for i in range(1, len(nums)):
            for j in range(len(nums)):
                if j >= i:
                    dp[i][j] = dp[0][j] + dp[i-1][j-1]
                    max_sum = max(max_sum, dp[i][j])

        #OUTPUT: largest sum of contiguous non-empty sequence of elements within array
        return max_sum
