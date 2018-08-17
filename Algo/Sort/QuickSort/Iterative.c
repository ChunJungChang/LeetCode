#include <stdio.h>

typedef struct {
    int start;
    int end;
} Range;

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

Range setRange(int s, int e) {
    Range r;
    r.start = s;
    r.end = e;
    
    return r;
}

void quick_sort(int* nums, int numsSize) {
    int idx = 0, left = 0, right = 0, start = 0, end = 0;
    Range r[numsSize];
    
    r[idx] = setRange(0, numsSize - 1);
    
    while (idx >= 0) {
        left = start = r[idx].start;
        end = r[idx].end;
        right = r[idx].end - 1;
        
        if (start >= end) {
            continue;
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
        
        if (start < left - 1) {
            r[idx] = setRange(start, left - 1);
        } else {
            idx--;
        }
        
        if (left + 1 < end) {
            r[++idx] = setRange(left + 1, end);
        }
    }
}

#define BUF_SIZE 8

int main(void) {
    int buf[BUF_SIZE] = {4, 7, 1, 9, 2, 5, 8, 3};
    
    print_arr(buf, BUF_SIZE);
    quick_sort(buf, BUF_SIZE);
    print_arr(buf, BUF_SIZE);
    
    return 0;
}
