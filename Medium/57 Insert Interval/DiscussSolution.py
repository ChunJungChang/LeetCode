class Solution:
    def insert(self, intervals, newInterval):
        
        # Constant to help us access start point and end point of interval
        START, END = 0, 1
        
        s, e = newInterval[START], newInterval[END]
        
        left, right = [], []
        
        for cur_interval in intervals:
            
            if cur_interval[END] < s:
                # current interval is on the left-hand side of newInterval
                left += [ cur_interval ]
                
            elif cur_interval[START] > e:
                # current interval is on the right-hand side of newInterval
                right += [ cur_interval ]
                
            else:
                # current interval has overlap with newInterval
                # merge and update boundary
                s = min(s, cur_interval[START])
                e = max(e, cur_interval[END])
                
        return left + [ [s, e] ] + right  
