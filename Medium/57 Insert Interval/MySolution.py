class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        newStartPlace = -1
        newEndPlace = -1
        ret = []
        
        for i in range(len(intervals)):
            if intervals[i][0] <= newInterval[0] and newInterval[0] <= intervals[i][1]:
                newStartPlace = intervals[i][0]
                break
        
        for i in range(len(intervals)):
            if intervals[i][0] <= newInterval[1] and newInterval[1] <= intervals[i][1]:
                newEndPlace = intervals[i][1]
                break
            if intervals[i][1] < newInterval[1] and i + 1 < len(intervals) and newInterval[1] < intervals[i + 1][0]:
                newEndPlace = newInterval[1]
                break
        
        
        if newStartPlace == -1:
            newStartPlace = newInterval[0]
        if newEndPlace == -1:
            newEndPlace = newInterval[1]
        for i in range(len(intervals)):
            if not (newStartPlace <= intervals[i][0] and intervals[i][1] <= newEndPlace):
                ret.append(intervals[i])
        ret.append([newStartPlace, newEndPlace])
        ret.sort()
        
        return ret
