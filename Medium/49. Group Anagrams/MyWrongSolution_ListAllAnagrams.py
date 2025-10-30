class Solution:
    def groupAnagramsHelp(self, strsItem: str) -> List[List[str]]:
        ret, tmp = [], []

        if strsItem == "":
            ret.append("")
            return ret
            
        for strsItemIdx in range(len(strsItem)):
            if  strsItemIdx == 0:
                ret = [strsItem[strsItemIdx]]
            else:
                tmp = ret.copy()
                ret.clear()

                while tmp:
                    tmpItem = tmp.pop(0)
                    for k in range(0, len(tmpItem) + 1):
                            tmpItemNew = ''.join((tmpItem[:k], strsItem[strsItemIdx], tmpItem[k:])) 
                            ret.append(tmpItemNew)

        return ret

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res, ret, tmp = [], [], []

        while strs:
            res.clear()
            tmp.clear()

            strsTarget = strs.pop(0)
            tmp.append(strsTarget)
            res = self.groupAnagramsHelp(strsTarget)
            while res:
                resItem = res.pop(0)
                for i in range(len(strs)):
                    if strs[i] == resItem:
                        tmp.append(resItem)
                        
            for tmpItem in tmp:
                if tmpItem in strs:
                    strs.remove(tmpItem)
            
            ret.append(tmp.copy())

        return ret
