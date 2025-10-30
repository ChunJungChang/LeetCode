class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        lastUp, lastLeft, lastStep = 0, 0, 0
        m, n = len(grid), len(grid[0])
        stepArr = [[0 for _ in range(n)] for _ in range(m)]
        
        stepArr[0][0] = grid[0][0]
        for i in range(1, m):
            stepArr[i][0] = stepArr[i - 1][0] + grid[i][0]
        for j in range(1, n):
            stepArr[0][j] = stepArr[0][j - 1] + grid[0][j]
        
        for i in range(1, m):
            for j in range(1, n):
                stepArr[i][j] = min(stepArr[i - 1][j], stepArr[i][j - 1]) + grid[i][j]
        
        return stepArr[m - 1][n - 1]
