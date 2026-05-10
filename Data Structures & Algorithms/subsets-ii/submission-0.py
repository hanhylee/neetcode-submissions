class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        # given array of integers which may contain duplicates
        nums.sort()
        res = []

        #--------------------------
        def backtrack(stack: List[int], i: int) -> None:
            nonlocal res

            if i == len(nums):
                res.append(stack.copy())
                return
            
            stack.append(nums[i])
            backtrack(stack, i+1)
            stack.pop()
            
            while i + 1 < len(nums) and nums[i] == nums[i+1]:
                i += 1
            backtrack(stack, i+1)

        #--------------------------

        backtrack([], 0)

        # return all possible subsets WITHOUT duplicates
        return res