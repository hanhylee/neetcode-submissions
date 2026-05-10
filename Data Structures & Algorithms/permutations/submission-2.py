class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        
        # ---------------------
        """
        if we pass in nums, memory complexity is O(n^2), time complexity is O(n^n)
        if we use a global set, time complexity is still O(n^n) but memory complexity is O(n)
        """
        def backtrack(nums: List[int], idx: int) -> None:
            nonlocal res

            if idx == len(nums):
                res.append(nums.copy())
                return

            for i in range(idx, len(nums)):
                nums[i], nums[idx] = nums[idx], nums[i]
                backtrack(nums, idx+1)
                nums[i], nums[idx] = nums[idx], nums[i]
                
        # ---------------------

        backtrack(nums, 0)

        return res