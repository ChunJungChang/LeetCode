class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ret = []
        
        if not nums:
            return [[]]
        
        cur = nums.pop()
        res = self.subsets(nums)
        
        print("cur: %d" % (cur))
        print("------------------------------")
        for i in res:
            print(*i, sep = ", ")
            ret.append(i)
        print("------------------------------")
        for i in res:
            print(*i + [cur], sep = ", ")
            ret.append(i + [cur])
        print("------------------------------")
        print(*ret, sep = ", ")
        print("==============================")
        
        return ret
