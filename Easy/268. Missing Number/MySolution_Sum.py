class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        nums_len = len(nums)
        sum = (1 + nums_len) * nums_len / 2
        
        for i in range(0, nums_len):
            sum -= nums[i]
        
        return int(sum)
