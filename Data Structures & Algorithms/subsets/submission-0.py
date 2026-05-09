class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        
        def backtrack(idx: int, stack: List[int]) -> None:
            nonlocal res
            if idx == len(nums):
                return
            for i, num in enumerate(nums):
                if i >= idx:
                    stack.append(nums[i])
                    res.append(stack.copy())
                    backtrack(i+1, stack)
                    stack.pop()

        backtrack(0, [])

        return res