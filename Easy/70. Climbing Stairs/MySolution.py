class Solution:
    def climbStairs(self, n: int) -> int:
        stepArr = [0, 1, 2];
        
        for i in range(3, n + 1):
            stepArr.insert(i, stepArr[i - 1] + stepArr[i - 2])
        
        return stepArr[n]
