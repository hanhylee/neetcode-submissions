class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) == 1:
            return intervals

        intervals.sort(key = lambda x: x[0])
        res = [intervals[0]]

        for interval in intervals[1:]:
            if interval[0] <= res[-1][1]:
                res[-1][0] = min(interval[0], res[-1][0])
                res[-1][1] = max(interval[1], res[-1][1])
            else:
                res.append(interval)

        return res