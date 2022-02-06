class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ret = []
        
        if not nums:
            return [[]]
        
        cur = nums.pop()
        res = self.subsets(nums)
        
        for i in res:
            ret.append(i + [cur])
        ret += res
        
        return ret
