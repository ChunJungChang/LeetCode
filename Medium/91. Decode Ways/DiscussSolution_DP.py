class Solution:
    def backtracking(self, s: str, cache: Dict[int, int]) -> int:
        sNum, ret, sFirstRes, sFirstTwoRes = 0, 0, 0, 0

        if len(s) in cache:
            ret = cache[len(s)]
        elif len(s) is 0:
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
            sFirstRes = self.backtracking(s[1:], cache)
            sNum = int(s[:2])
            if sNum >= 1 and sNum <= 26:
                sFirstTwoRes = self.backtracking(s[2:], cache)
            ret = sFirstRes + sFirstTwoRes
            cache[len(s)] = ret
                
        return ret

    def numDecodings(self, s: str) -> int:
        ret = 0
        cache = {}

        ret = self.backtracking(s, cache)

        return ret
