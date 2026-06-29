"""
Algorithm
Start the binary search with start = matrix[0][0] and end = matrix[N-1][N-1]
Find the middle of the start and the end. This middle number is NOT necessarily an element in the matrix.
Count all the numbers smaller than or equal to middle in the matrix. As the matrix is sorted, we can do this in O(N). Note that this is determining the size of the left-half of the array.
While counting, we need to keep track of the smallest number greater than the middle (let’s call it R) and at the same time the biggest number less than or equal to the middle (let’s call it L). These two numbers will be used to adjust the number range for the binary search in the next iteration.
If the count is equal to K, L will be our required number as it is the biggest number less than or equal to the middle, and is definitely present in the matrix.
If the count is less than K, we can update start = R to search in the higher part of the matrix
If the count is greater than K, we can update end = L to search in the lower part of the matrix in the next iteration.
"""

class Solution:
    
    def countLessEqual(self, matrix, mid, smaller, larger):
        
        count, n = 0, len(matrix)
        row, col = n - 1, 0
        
        while row >= 0 and col < n:
            if matrix[row][col] > mid:
               
                # As matrix[row][col] is bigger than the mid, let's keep track of the
                # smallest number greater than the mid
                larger = min(larger, matrix[row][col])
                row -= 1
                
            else:
                
                # As matrix[row][col] is less than or equal to the mid, let's keep track of the
                # biggest number less than or equal to the mid
                
                smaller = max(smaller, matrix[row][col])
                count += row + 1
                col += 1

        return count, smaller, larger
    
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        
        n = len(matrix)
        start, end = matrix[0][0], matrix[n - 1][n - 1]
        while start < end:
            mid = start + (end - start) / 2
            smaller, larger = (matrix[0][0], matrix[n - 1][n - 1])

            count, smaller, larger = self.countLessEqual(matrix, mid, smaller, larger)

            if count == k:
                return smaller
            if count < k:
                start = larger  # search higher
            else:
                end = smaller  # search lower

        return start
