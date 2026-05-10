class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        tracker = [False for num in nums]
        
        # ---------------------
        """
        if we pass in nums, memory complexity is O(n^2), time complexity is O(n^n)
        if we use a global set, time complexity is still O(n^n) but memory complexity is O(n)
        """
        def backtrack(stack: List[int]) -> None:
            nonlocal res

            if len(stack) == len(nums):
                res.append(stack.copy())

            for i in range(len(nums)):
                if tracker[i]:
                    continue

                stack.append(nums[i])
                tracker[i] = True

                backtrack(stack)

                stack.pop()
                tracker[i] = False
                
        # ---------------------

        backtrack([])

        return res