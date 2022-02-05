"""
STEP 1 : Create a 2D array with default value 0, which is the state[i][j] in my solution.
STEP 2 : Initialize the first row and first column in two loops. Set the value of certain location to be 1 if its corresponding location in obstacleGrid is 0 (meaning no obstacle). Break the loop if an obstacle is encountered in the obstacleGrid. The values of locations after the obstacle remain 0.
STEP 3: The value of each location is the sum of the values above and on the left (state[i][j] = state[i-1][j] + state[i][j-1]). Don't forget the edge case where there's only one row or one column.
"""

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if not len(obstacleGrid) or not len(obstacleGrid[0]):
            return None
        # STEP 1
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        state = [[0 for _ in range(n)] for _ in range(m)]
		
		# STEP 2
        for i in range(m):
            if obstacleGrid[i][0] == 1:
                break
            else:
                state[i][0] = 1
        for j in range(n):
            if obstacleGrid[0][j] == 1:
                break
            else:
                state[0][j] = 1
				
        # STEP 3
        if m == 1:
            return state[0][-1]
        if n == 1:
            return state[-1][0]
        
        for i in range(1, m):
            for j in range(1, n):
                if obstacleGrid[i][j]:
                    continue
                else:
                    state[i][j] = state[i-1][j] + state[i][j-1]
        
        return state[m-1][n-1]
