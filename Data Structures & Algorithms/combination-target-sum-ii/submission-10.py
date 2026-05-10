class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        # input: list of integers which can be chosen once or more

        candidates.sort()
        res = []
        
        def backtrack(stack: List[int], currSum: int, idx: int) -> None:
            nonlocal res

            # base case
            if currSum == target:
                res.append(stack.copy())
                return
            
            # iteration
            for i in range(idx, len(candidates)):
                if i > idx and candidates[i] == candidates[i-1]:
                    continue
                
                if currSum + candidates[i] > target:
                    continue

                # add to stack and currSum
                stack.append(candidates[i])
                currSum += candidates[i]

                # recursive call
                backtrack(stack, currSum, i+1)

                # undo
                stack.pop()
                currSum -= candidates[i]

        backtrack([], 0, 0)

        # return: combinations that sum to target. do not return duplicates
        return res