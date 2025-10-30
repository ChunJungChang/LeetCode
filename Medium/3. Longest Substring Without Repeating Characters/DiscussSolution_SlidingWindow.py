class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        letterIdxMap = {}
        leftIdx, ret, i = 0, 0, 0

        for i in range(len(s)):
            if s[i] in letterIdxMap:
                """
                letterIdxMap[s[i]] + 1 is max: For example, a b c d e a, the result is b c d e a when i is 5 and leftIdx is 0.
                leftIdx is max: For example, a b c d e b a, the result is b a when i is 6 and leftIdx is 5.
                """
                leftIdx = max(letterIdxMap[s[i]] + 1, leftIdx)

            ret = max(ret, i - leftIdx + 1)
            letterIdxMap[s[i]] = i

        return ret
