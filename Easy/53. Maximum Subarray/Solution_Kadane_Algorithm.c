int maxSubArray(int* nums, int numsSize){
    int curSum = nums[0], globalSum = nums[0], i = 0;
    
    if (!nums) {
        globalSum = 0;
        return globalSum;
    }
    if (numsSize == 1) {
        globalSum = nums[0];
        return globalSum;
    }
    
    for (i = 1; i < numsSize; i++) {
        if (curSum + nums[i] > nums[i]) {
            curSum += nums[i];
        } else {
            curSum = nums[i];
        }
        
        if (globalSum < curSum) {
            globalSum = curSum;
        }
    }
    
    return globalSum;
}
