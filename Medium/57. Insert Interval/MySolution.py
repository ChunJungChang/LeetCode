class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        newStartVal = -1
        newEndVal = -1
        ret = []
        
        for i in range(len(intervals)):
            if intervals[i][0] <= newInterval[0] and newInterval[0] <= intervals[i][1]:
                newStartVal = intervals[i][0]
                break
        
        for i in range(len(intervals)):
            if intervals[i][0] <= newInterval[1] and newInterval[1] <= intervals[i][1]:
                newEndVal = intervals[i][1]
                break
            if intervals[i][1] < newInterval[1] and i + 1 < len(intervals) and newInterval[1] < intervals[i + 1][0]:
                newEndVal = newInterval[1]
                break
        
        
        if newStartVal == -1:
            newStartVal = newInterval[0]
        if newEndVal == -1:
            newEndVal = newInterval[1]
        for i in range(len(intervals)):
            if not (newStartVal <= intervals[i][0] and intervals[i][1] <= newEndVal):
                ret.append(intervals[i])
        ret.append([newStartVal, newEndVal])
        ret.sort()
        
        return ret
