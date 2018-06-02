#include <stdio.h>

void print_arr(int* nums, int numsSize) {
    int i = 0;
    
    for (i = 0 ; i < numsSize ; i++) {
        printf("%d, ", nums[i]);
    }
    printf("\n");
}

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
        /**
         * Why nums[left] "<=" nums[end] is,
         * not nums[left] "<" nums[end].
         * Try Example {1, 1, 1, 1}
         */
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
        /**
         * If ignore this else condition,
         * the answer will be fault.
         * Try Example {4, 0, 6}
         */
        left = end;
    }

    if (left > 0) {
        quick_sort(start, left - 1, nums);
    }
    quick_sort(left + 1, end, nums);
}

#define BUF_SIZE 8

int main(void) {
    int buf[8] = {4, 7, 1, 9, 2, 5, 8, 3};
    
    print_arr(buf, BUF_SIZE);
    quick_sort(0, BUF_SIZE - 1, buf);
    print_arr(buf, BUF_SIZE);
    
    return 0;
}
