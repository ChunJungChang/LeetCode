class Solution:
    def spiralOrderHelp(self, matrix: List[List[int]]):
        ret = []

        # Remove the first column of matrix.
        if not matrix:
            return ret

        firstCol = matrix.pop(0)
        for item in firstCol:
            ret.append(item)
        
        # Remove last item from "the second column" to "the second to last column" of matrix.
        if not matrix:
            return ret

        for i in range(len(matrix) - 1):
            if matrix[i]:
                ret.append(matrix[i].pop())
        
        # Remove the last column of matrix.
        if not matrix:
            return ret

        lastCol = matrix.pop()
        while lastCol:
            ret.append(lastCol.pop())

        # Remove first item from "the second to last column" to "the second column" of matrix.
        if not matrix:
            return ret

        for i in reversed(range(len(matrix))):
            if matrix[i]:
                ret.append(matrix[i].pop(0))

        return ret

    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res, ret = [], []

        while matrix:
            # Python is "Pass by Assignment".
            res = self.spiralOrderHelp(matrix)
            for resItem in res:
                ret.append(resItem)
    
        return ret
