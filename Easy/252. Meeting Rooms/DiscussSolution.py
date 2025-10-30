def getStartTime(interval: List[int]) -> int:
            return interval[0]

class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        intervalsSortStartTime = sorted(intervals, key = getStartTime)
        #intervalsSortStartTime = sorted(intervals, key = lambda x: x[0])

        for i in range(len(intervalsSortStartTime) - 1):
            if intervalsSortStartTime[i][1] > intervalsSortStartTime[i + 1][0]:
                return False
        
        return True
