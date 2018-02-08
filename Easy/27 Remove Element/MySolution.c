int removeElement(int* nums, int numsSize, int val) {
    int i = 0, j, len = 0;
    int *cur = nums, *find = nums;

    for (i = 0 ; i < numsSize ; i++) {
        if (*(cur + i) == val) {
            j = i;
            j++;
            for (j ; j < numsSize ; j++) {
                if (*(cur + j) != val) {
                    int tmp = *(cur + i);
                    *(cur + i) = *(cur + j);
                    *(cur + j) = tmp;
                }
            }
        }
    }

    for (i = 0 ; i < numsSize ; i++) {
        if (*(cur+i) != val) {
            len++;
        } else {
            return len;
        }
    }

    return numsSize;
}
