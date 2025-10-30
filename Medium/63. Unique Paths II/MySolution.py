class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        
        stepArr = [[0 for i in range(n)] for j in range(m)];
        
        for i in range(m):
            stepArr[i][0] = 1
        for j in range(n):
            stepArr[0][j] = 1
        for i in range(m):
            for j in range(n):
                if (obstacleGrid[i][j] == 1):
                    stepArr[i][j] = -1
        for i in range(m):
            if (obstacleGrid[i][0] == 1):
                for ii in range(i, m):
                    stepArr[ii][0] = -1
                break
        for j in range(n):
            if (obstacleGrid[0][j] == 1):
                for jj in range(j, n):
                    stepArr[0][jj] = -1
                break
        
        for i in range(1, m):
            for j in range(1, n):
                if stepArr[i][j] == -1:
                    continue
                elif stepArr[i - 1][j] == -1 and stepArr[i][j - 1] == -1:
                    stepArr[i][j] = -1
                elif stepArr[i - 1][j] == -1 or stepArr[i][j - 1] == -1:
                    stepArr[i][j] = stepArr[i - 1][j] + stepArr[i][j - 1] + 1
                else:
                    stepArr[i][j] = stepArr[i - 1][j] + stepArr[i][j - 1]
        
        res = stepArr[m - 1][n - 1]
        if obstacleGrid[0][0] == 1:
            res = 0
        elif obstacleGrid[m - 1][n - 1] == 1:
            res = 0
        elif stepArr[m - 1][n - 1] < 0:
            res = 0

        return res
