class Solution:
    def longestPalindrome(self, s: str) -> str:
        sLength = len(s)
        curStr, ret = "", ""
        i, j, k = 0, 0, 0
        isEven = False

        for i in range(sLength):
            """
            Handle special cases, ...a..., ...aa..., ...aaa..., ...aaaa..., etc.
            Calculate the number of palindromic substring which is build by the same letters is odd or even.
            """
            isEven = False
            j, k = 0, 0
            curStr = ""
            while i - 1 - j >= 0 and s[i] == s[i - 1 - j]:
                j += 1
            while i + 1 + k <= sLength - 1 and s[i] == s[i + 1 + k] :
                k += 1
            if (1 + j + k) % 2 == 1: # 1 is for s[i]
                isEven = False
                curStr = s[i]
            else:
                isEven = True
                for l in range(1 + j + k):
                    curStr = curStr + s[i]

            if isEven == False:
                j = 0
                while i - 1 - j >= 0 and i + 1 + j <= sLength - 1:
                    if s[i - 1 - j] == s [i + 1 + j]:
                        curStr = s[i - 1 - j] + curStr + s [i + 1 + j]
                        j += 1
                    else:
                        break
            elif isEven == True:
                while i - 1 - j >= 0 and i + 1 + k <= sLength - 1:
                    if s[i - 1 - j] == s [i + 1 + k]:
                        curStr = s[i - 1 - j] + curStr + s [i + 1 + k]
                        j += 1
                        k += 1
                    else:
                        break
            
            if (len(curStr) > len(ret)):
                ret = curStr

        return ret
                    
