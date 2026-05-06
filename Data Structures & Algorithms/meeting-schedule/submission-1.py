"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:
        if len(intervals) <= 1:
            return True

        intervals.sort(key = lambda x: x.start)

        last_meeting_end = intervals[0].end

        for interval in intervals[1:]:
            if interval.start < last_meeting_end:
                return False
            last_meeting_end = interval.end
        
        return True
