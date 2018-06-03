int arrayPairSum(int* nums, int numsSize) {
    int hasttable[20001] = {0}; // -10000~10000
    int i = 0, cnt = 0, max_times = numsSize / 2, sum = 0,
        min = 10000, max = -10000;
    bool odd_times = false;
    
    for (i = 0 ; i < numsSize ; i++) {
        hasttable[nums[i] + 10000]++;
        
        if (nums[i] < min) {
            min = nums[i];
        }
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    
    for (i = min + 10000 ; i <= max + 10000 && cnt < max_times ; i++) {
        if (hasttable[i] > 0) {
            sum = sum + (i - 10000) * (hasttable[i] / 2);
            
            if (!odd_times && (hasttable[i] % 2 == 1)) {
                sum = sum + (i - 10000);
            }
            
            /**
              * odd_times ^ (hasttable[i] % 2 == 1)
              * odd_times means last time is odd times or not
              * hasttable[i] % 2 == 1 means this time is odd times or not
              */
            odd_times = odd_times ^ (hasttable[i] % 2 == 1);
        }
    }
    
    return sum;
}
