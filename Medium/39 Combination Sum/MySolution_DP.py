class Solution:
    def combinationSumHelp(self, candidates: List[int], target: int, idx: int) -> List[List[int]]:
        resTake, resNotTake = [], []
        ret = []

        if target in candidates:
            ret.append([target])
            candidates[:-1]

        # Take candidates[idx].
        if target - candidates[idx] >= candidates[0]:
            resTake = self.combinationSumHelp(candidates, target - candidates[idx], idx)
            for item in resTake:
                item.insert(0, candidates[idx])
            for item in resTake:
                ret.append(item)

        
        # Not take candidates[idx].
        if idx - 1 >= 0:
            resNotTake = self.combinationSumHelp(candidates, target, idx - 1)
            for item in resNotTake:
                ret.append(item)

        return ret


    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        ret = []

        candidates.sort()

        res = self.combinationSumHelp(candidates, target, len(candidates) - 1)

        # Remove duplicate items in the list.
        for item in res:
            item.sort(reverse = True)
            if item not in ret:
                ret.append(item)
        return ret
