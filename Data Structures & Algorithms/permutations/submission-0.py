class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        used = set()
        
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
                if nums[i] in used:
                    continue

                stack.append(nums[i])
                used.add(nums[i])

                backtrack(stack)

                stack.pop()
                used.remove(nums[i])
                
        # ---------------------

        backtrack([])

        return res