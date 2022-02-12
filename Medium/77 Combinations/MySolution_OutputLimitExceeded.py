class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ret = []
        
        def backtracking(cur, cnt, combList):    
            if cnt == 1:
                for i in range(cur, n + 1):
                    combList.append(i)
                    ret.append(combList.copy())
                    combList.pop()
                return
            
            for i in range(cur, n):
                if (i + cnt - 1) <= n: # Stop earlier
                    combList.append(i)
                    backtracking(i + 1, cnt - 1, combList)
                    combList.pop()
        
        backtracking(1, k, [])

        return ret
