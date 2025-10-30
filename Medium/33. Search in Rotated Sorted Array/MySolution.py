class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def binary_search(nums, target, startIdx, endIdx):
            midIdx = floor((startIdx + endIdx) / 2)
            mid = nums[midIdx]
            start = nums[startIdx]
            end = nums[endIdx]
            
            if (startIdx >= endIdx and target != nums[startIdx]):
                return -1

            if (target == start):
                return startIdx
            elif (target == mid):
                return midIdx
            elif (target == end):
                return endIdx
            
            if (start < mid and start < target and target < mid):  # Normal Case
                return binary_search(nums, target, startIdx, midIdx)
            elif (mid < end and mid < target and target < end): # Normal Case
                return binary_search(nums, target, midIdx + 1, len(nums) - 1)
            elif (start > mid ): # Abnormal Case, [7 8 9 0 1 2] need to handle [7 8 9] and [0 1 2]
                if ((start < target and target > mid) or (start > target and target < mid)):
                    return binary_search(nums, target, startIdx, midIdx)
                else:
                    return -1
            elif (mid > end): # Abnormal Case, [7 8 9 0 1 2] need to handle [7 8 9] and [0 1 2]
                if ((mid < target and target > end) or (mid > target and target < end)):
                    return binary_search(nums, target, midIdx + 1, len(nums) - 1)
                else:
                    return -1
            else:
                return -1
        
        return binary_search(nums, target, 0, len(nums) - 1)
