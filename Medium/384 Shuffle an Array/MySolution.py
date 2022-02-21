class Solution:
    
    def __init__(self, nums: List[int]):
        self._nums = nums
        self._nums_len = len(nums)
        
    def reset(self) -> List[int]:
        return self._nums;

    def shuffle(self) -> List[int]:
        _nums_copy = self._nums.copy()
        ret = []

        for i in range(self._nums_len, 0, -1):
            chosen_position = random.randrange(0, i)
            ret.append(_nums_copy[chosen_position])
            _nums_copy.pop(chosen_position)
        
        return ret;


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
