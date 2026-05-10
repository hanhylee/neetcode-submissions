class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        # given array of integers which may contain duplicates

        # sort array so that we can avoid duplication
        nums.sort()
        res = []

        #--------------------------
        def backtrack(stack: List[int], i: int) -> None:
            nonlocal res

            # termination step
            if i == len(nums):
                res.append(stack.copy())
                return
            
            # choose to include current element
            stack.append(nums[i])
            backtrack(stack, i+1)
            stack.pop()
            
            # choose not to include current element + same elements
            while i + 1 < len(nums) and nums[i] == nums[i+1]:
                i += 1
            backtrack(stack, i+1)

        #--------------------------

        backtrack([], 0)

        # return all possible subsets WITHOUT duplicates
        return res