

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize){
    /**
     * nums = [1, 2, 2, 4]
     */
    
    int res = 0, bit = 0, xor1 = 0, xor2 = 0, i = 0;
    int *ret = NULL;
    
    ret = (int *)malloc(2 * sizeof(int));
    if (!ret) {
        *returnSize = 0;
        return NULL;
    }
    
    /**
     * res = repetition of one ^ loss of another number
     * res = (1 ^ 2 ^ 2 ^ 4) ^ (1 ^ 2 ^ 3 ^ 4) => 2 ^ 3
     */
    for (i = 0; i < numsSize; i++) {
        res ^= nums[i];
    }
    for (i = 1; i <= numsSize; i++) {
        res ^= i;
    }
    
    /**
     * Find the rightmost digit of res which value is 1,
     * because repetition of one and loss of another number are different number
     */
    bit = res & ~(res - 1);
    
    /**
     * Find these two number, not sure which one is repetition or loss
     * nums [1, 2, 2, 4] split into [1] and [2, 2, 4]
     * sum [1, 2, 3, 4] split into [1, 3] and [2, 4]
     * xor1 = (1) ^ (1, 3) = 3
     * xor2 = (2, 2, 4) ^ (2, 4) = 2
     */
    for (i = 0; i < numsSize; i++) {
        if (nums[i] & bit) {
            xor1 ^= nums[i];
        } else {
            xor2 ^= nums[i];
        }
    }
    for (i = 1; i <= numsSize; i++) {
        if (i & bit) {
            xor1 ^= i;
        } else {
            xor2 ^= i;
        }
    }
    
    /**
     * Check xor1 is repetition or not,
     * if xor1 is not repetition, xor1 is loss
     */
    for (i = 0; i < numsSize; i++) {
        if (xor1 == nums[i]) {
            ret[0] = xor1;
            ret[1] = xor2;
            *returnSize = 2;

            return ret; 
        }
    } 
    
    ret[0] = xor2;
    ret[1] = xor1;
    *returnSize = 2;

    return ret;
}
