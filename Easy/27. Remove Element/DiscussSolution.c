int removeElement(int* nums, int numsSize, int val) {
    int i, j;
    for (i = j = numsSize - 1 ; i >= 0 ; i--)
        if (nums[i] == val && i != j--) nums[i] = nums[j + 1];
    
    return j + 1;
}
