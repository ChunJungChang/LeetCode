class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        lowIdx = 0
        highIdx = len(nums) - 1
        
        nums.sort()
        
        while (lowIdx <= highIdx):
            mid = int((lowIdx + highIdx) / 2)

            if nums[mid] == mid:
                lowIdx = mid + 1
            else:
                highIdx = mid - 1;
                
        return lowIdx
