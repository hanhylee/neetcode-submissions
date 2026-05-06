"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        """
        intervals=[(5,10),(15,20),(0,40)]
        start with (5, 10)
        (15, 20) does not overlap
        non-overlapping area is now (5, 20)
        (0, 40) overlaps this area so we need 1 more room
        with 1 more room, we cover (0, 40)

        sice we sorted by the end time, any subsequent interval will increase
        the number of rooms needed IF it falls within (5, 20)
        
        we need to keep track of all the overlapping areas and the number of rooms needed to accommodate?

        ALTERNATIVELY
        sort by start time
        intervals=[(0,40),(5,10),(15,20)]
        
        use a stack. if the top of the stack's end time is greater than the start time of the next, we pop the stack
        and increment the rooms needed for that interval, then add the remainder


        """
        
        if len(intervals) <= 1:
            return len(intervals)

        start_times = list(map(lambda x: x.start, intervals))
        start_times.sort()
        print(start_times)
        end_times = list(map(lambda x: x.end, intervals))
        end_times.sort()
        print(end_times)

        min_rooms = 0
        count = 1
        s = 0
        e = 0

        while s < len(start_times) - 1:
            s += 1
            if start_times[s] < end_times[e]:
                count += 1
            else:
                e += 1
            min_rooms = max(min_rooms, count)
        
        return min_rooms