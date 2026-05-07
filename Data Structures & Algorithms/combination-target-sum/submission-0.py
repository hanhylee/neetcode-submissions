class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        # given list of distinct integers
        # given target
        # list all unique combinations of nums that sum to target
        # can reuse a number unlimited times

        """
        APPROACH
        - backtracking
        - go through each coin and add them to a growing list
        - if total == target, add that to output array
        - if total > target, backtrack
        - to avoid duplications, only consider coins that are equal or of a later position in the list of coins
        """
        
        res = []

        def backtrack(stack: List[int], start_idx: int, total: int) -> None:
            nonlocal res
            if start_idx >= len(nums):
                return
            if total == target:
                res.append(stack)
                return
            if total > target:
                return
            
            for i in range(len(nums)):
                if i >= start_idx:
                    stack.append(nums[i])
                    total += nums[i]
                    backtrack(list(stack), i, total)
                    stack.pop()
                    total -= nums[i]
            
        backtrack([], 0, 0)

        # return: combinations that sum to order
        return res
