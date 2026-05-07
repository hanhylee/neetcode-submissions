class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        #INPUT: list of integers

        """
        BRUTE FORCE:
        - dynamic sliding window starting from the widest window all the way to the smallest
        - calculate the sum of elements in the window -> return the max
        - O(n^2)

        DYNAMIC PROGRAMMING:
        - calculate sums in a 2D array where each column represents the maximum sum when the row'th element is added
           |    2    -3     4    -2   2   1   -1   4
        -----------------------------------------------
         0 |    2    -3     4    -2   2   1   -1   4
         1 |         -1     1     2   0   3   0    3
         2 |                3     -1  4   1   2    4
         3 |         
        - recurrence relation: dp[r][c] = dp[0][c] + dp[r-1][c-1]
        - update max_sum as dp gets built
        - O(n^2)
    
        DYNAMIC PROGRAMMING ALTERNATIVE:
        nums = [2,-3,4,-2,2,1,-1,4]
        
        dp = [2, -1, 4, 2]
        - chose 2
        - didn't choose -3 because it would be < 0
        - chose 4 -> update max
        - chose -2 because running total > 0
        - chose 2 because running total > 0
        - chose 1
        - chose -1
        - chose 4

        """

        if len(nums) == 1:
            return nums[0]

        dp = [x for x in nums]
        max_sum = nums[0]

        for i, num in enumerate(nums[1:]):
            dp[i+1] = max(num, dp[i] + num)
            max_sum = max(dp[i+1], max_sum)

        #OUTPUT: largest sum of contiguous non-empty sequence of elements within array
        return max_sum
