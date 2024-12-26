class Solution:
    def combinationSumHelp(self, candidates: List[int], target: int, idx: int) -> List[List[int]]:
        res, resTake, resNotTake = [], [], []
        ret = []

        #  Just add the element to result and slice list if the element of the list is equal to target.
        if target in candidates:
            ret.append([target])
            candidates = candidates[:candidates.index(target)]
            res = self.combinationSumHelp(candidates, target, len(candidates) - 1)
            for item in res:
                ret.append(item)
        else:
            # Take candidates[idx].
            if idx >= 0 and target - candidates[idx] >= 0:
                resTake = self.combinationSumHelp(candidates, target - candidates[idx], idx)
                for item in resTake:
                    item.insert(0, candidates[idx])
                for item in resTake:
                    ret.append(item)

            # Not take candidates[idx].
            if idx - 1 >= 0 and target > 0:
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
