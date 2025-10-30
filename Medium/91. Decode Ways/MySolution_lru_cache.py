from functools import lru_cache

class Solution:
    @lru_cache(maxsize=None)

    def backtracking(self, s: str) -> int:
        sNum, ret, sFirstRes, sFirstTwoRes = 0, 0, 0, 0

        if len(s) is 0:
            ret = 1
        elif len(s) is 1:
            sNum = int(s)
            if sNum >= 1 and sNum <= 26:
                ret = 1
            else:
                ret = 0
        elif int(s[:1]) is 0:
            ret = 0
        else:
            sFirstRes = self.backtracking(s[1:])
            sNum = int(s[:2])
            if sNum >= 1 and sNum <= 26:
                sFirstTwoRes = self.backtracking(s[2:])
            ret = sFirstRes + sFirstTwoRes
                
        return ret

    def numDecodings(self, s: str) -> int:
        ret = 0

        ret = self.backtracking(s)

        return ret
