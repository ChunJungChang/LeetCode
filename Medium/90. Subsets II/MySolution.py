class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ret = []
        
        if not nums:
            ret.append([])
            return ret
        
        nums.sort()
        
        cur = nums.pop()
        
        res = self.subsetsWithDup(nums)
        for i in res:
            ret.append(i + [cur])
        for i in res:
            if i in ret:
                continue
            ret.append(i)
        
        return ret
