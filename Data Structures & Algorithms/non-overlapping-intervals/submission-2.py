class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        """
        INPUT: 
        - list of intervals
        - each interval has a start time and end time

        BRUTE FORCE:
        - backtracking w/ O(2**n) TC
        - can memoize

        OUTPUT:
        - minimum number of intervals that we need to remove for non-overlapping
        """

        min_val = len(intervals)
        intervals.sort(key = lambda x: x[0])

        def backtrack(stack: list, removed: int, idx: int) -> None:
            nonlocal min_val
            
            # termination
            if len(stack) + removed == len(intervals):
                min_val = min(removed, min_val)

            # for loop
            for i, interval in enumerate(intervals[idx:]):
                if not stack or interval[0] >= stack[-1][1]:
                    stack.append(interval)
                    backtrack(stack, removed + i, idx + i + 1)
                    stack.pop()
        
        backtrack([], 0, 0)

        return min_val