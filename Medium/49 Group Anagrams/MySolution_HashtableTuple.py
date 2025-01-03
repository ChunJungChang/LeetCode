class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ret = []

        while strs:
            strsTargetTuple = ()
            tmp = []

            strsTarget = strs.pop(0)
            tmp.append(strsTarget)

            for i in range(len(strs)):
                strsTargetTuple = tuple(strsTarget)

                strsTmp = strs[i]
                if len(strsTarget) != len(strsTmp):
                    continue

                for j in range(len(strsTmp)):
                    if strsTmp[j] not in strsTargetTuple:
                        break
                    else:
                        strsTargetList = list(strsTargetTuple)
                        strsTargetList.remove(strsTmp[j])
                        strsTargetTuple = tuple(strsTargetList)

                if not strsTargetTuple:
                    tmp.append(strsTmp)
            
            for tmpItem in tmp:
                if tmpItem in strs:
                    strs.remove(tmpItem)
            
            ret.append(tmp)

        return ret
