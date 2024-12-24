class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        ret = []
        seen = set()

        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in seen:
                if [complement, nums[i]] not in ret:
                    ret.append([complement, nums[i]])
            seen.add(nums[i])
        
        return ret

    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        ret = []
        retNoDuplicate = []
        retSet = set()

        for i in range(len(nums)):
            if nums[i] > 0:
                break

            complement = 0 - nums[i]
            res = self.twoSum(nums[i+1:], complement)
            if res:
                for item in res:
                    item.insert(0, nums[i])
                    ret.append(item)
        
        # Remove duplicate items in the list.
        for item in ret:
            if frozenset(item) not in retSet:
                retNoDuplicate.append(item)
                retSet.add(frozenset(item))
        return retNoDuplicate
