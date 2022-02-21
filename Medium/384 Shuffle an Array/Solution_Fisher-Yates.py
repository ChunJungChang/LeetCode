class Solution:
    
    def __init__(self, nums: List[int]):
        self.ret = nums
        self.orig = list(nums)
        
    def reset(self) -> List[int]:
        self.ret = self.orig
        self.orig = list(self.orig)
        return self.ret

    def shuffle(self) -> List[int]:
        for i in range(len(self.ret)):
            chosen_position = random.randrange(i, len(self.ret))
            self.ret[i], self.ret[chosen_position] = self.ret[chosen_position], self.ret[i]
        
        return self.ret;


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
