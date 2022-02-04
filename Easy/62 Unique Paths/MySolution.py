class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        stepArr = [[0 for i in range(n)] for j in range(m)] ;
        
        for i in range(m):
            stepArr[i][0] = 1
        for j in range(n):
            stepArr[0][j] = 1
            
        for i in range(1, m):
            for j in range(1, n):
                stepArr[i][j] = stepArr[i - 1][j] + stepArr[i][j - 1]
        
        return stepArr[m - 1][n - 1]
