class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        targetSubI = 0
        
        for i in range(len(nums)):
            targetSubI = target - nums[i]
            for j in range(i + 1, len(nums)):
                if nums[j] == targetSubI:
                    return [i, j] # exactly one solution
