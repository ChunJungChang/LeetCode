class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ret = []

        while strs:
            strsTargetList = []
            tmpRet = []

            strsTarget = strs.pop(0)
            tmpRet.append(strsTarget)

            for i in range(len(strs)):
                strsTargetList = list(strsTarget)

                strsTmp = strs[i]
                if len(strsTarget) != len(strsTmp):
                    continue

                for j in range(len(strsTmp)):
                    if strsTmp[j] not in strsTargetList:
                        break
                    else:
                        strsTargetList.remove(strsTmp[j])

                if not strsTargetList:
                    tmpRet.append(strsTmp)
            
            for tmpRetItem in tmpRet:
                if tmpRetItem in strs:
                    strs.remove(tmpRetItem)
            
            ret.append(tmpRet)

        return ret
