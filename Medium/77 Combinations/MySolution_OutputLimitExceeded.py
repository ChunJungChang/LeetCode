class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ret = []
        
        def backtracking(start, cnt):
            res = []
            
            if cnt == 1:
                for i in range(start, n + 1):
                    res.append([i])
                return res
            
            for i in range(start, n):
                tmp = backtracking(i + 1, cnt - 1)
                for item in tmp:
                    res.append([i] + item.copy())
            return res

        ret = backtracking(1, k)
        return ret
