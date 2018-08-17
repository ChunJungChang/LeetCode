#include <stdio.h>

void print_arr(int* nums, int numsSize) {
    int i = 0;
    
    for (i = 0 ; i < numsSize ; i++) {
        printf("%d, ", nums[i]);
    }
    printf("\n");
}

void bubble_sort(int* nums, int numsSize) {
    int i = 0, j = 0, tmp = 0;
    
    for (i = 0 ; i < numsSize ; i++) {
        for (j = 0 ; j < numsSize - i - 1 ; j++) {
            if (nums[j] > nums[j + 1]) {
                tmp = *(nums + j + 1);
                *(nums + j + 1) = *(nums + j);
                *(nums + j) = tmp;
            }
        }
    }
}

#define BUF_SIZE 8

int main(void) {
    int buf[8] = {4, 7, 1, 9, 2, 5, 8, 3};
    
    print_arr(buf, BUF_SIZE);
    bubble_sort(buf, BUF_SIZE);
    print_arr(buf, BUF_SIZE);
    
    return 0;
}
