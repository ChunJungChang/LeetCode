void swap(int* p, int* q) {
    int tmp = 0;
    
    tmp = *p;
    *p = *q;
    *q = tmp;
}

void quick_sort(int start, int end, int* nums) {
    int left = start, right = end - 1;
    
    if (start >= end) {
        return;
    }
    
    while (left < right) {
        while (nums[left] <= nums[end] && left < right) {
            left++;
        }
        while (nums[right] >= nums[end] && right > left) {
            right--;
        }
        if (left != right) {
            swap(&nums[left], &nums[right]);
        }
    }
    
    if (nums[left] > nums[end]) {
        swap(&nums[left], &nums[end]);
    } else {
        left = end;
    }

    if (left > 0) {
        quick_sort(start, left - 1, nums);
    }
    quick_sort(left + 1, end, nums);
}

int arrayPairSum(int* nums, int numsSize) {
    int i = 0, j = 0, tmp = 0, sum = 0;
    
    /* Quick Sort Recursive */
    quick_sort(0, numsSize - 1, nums);

    for (i = 0 ; i < numsSize ; i += 2) {
        sum += nums[i];
    }
    
    return sum;
}
