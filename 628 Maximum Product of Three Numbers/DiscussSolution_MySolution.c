int maximumProduct(int* nums, int numsSize) {
    int *nums_tmp = nums;
    int i = 0, j = 0;
    int biggest, bigger, big, small, smaller, smallest;
    int neg_cnt = 0, zero_cnt = 0, pos_cnt = 0;
    int result = 0;
    
    if (numsSize == 3) {
        result = *(nums_tmp + 0) * *(nums_tmp + 1) * *(nums_tmp + 2);
        return result;
    }
    
    biggest  = -2147483648;
    bigger   = -2147483647;
    big      = -2147483646;
    smaller  = 2147483646;
    smallest = 2147483647;
    for (i = 0 ; i < numsSize ; i++) {
        /*
        if (*(nums_tmp + i) < 0)
            neg_cnt++;
        else if (*(nums_tmp + i) == 0)
            zero_cnt++;
        else if (*(nums_tmp + i) > 0)
            pos_cnt++;
        */

        if (*(nums_tmp + i) >= biggest) { //*(nums_tmp + i) is bigger than biggest, bigger and big
            big = bigger;
            bigger = biggest;
            biggest = *(nums_tmp + i);
        } else if (*(nums_tmp + i) >= bigger) { // *(nums_tmp + i) is between biggest and bigger
            big = bigger;
            bigger = *(nums_tmp + i);
        } else if (*(nums_tmp + i) >= big) { // *(nums_tmp + i) is between bigger and big
            big = *(nums_tmp + i);
        }
        
        if (*(nums_tmp + i) <= smallest) { // *(nums_tmp + i) is less than smaller and smallest
            smaller = smallest;
            smallest = *(nums_tmp + i);
        } else if (*(nums_tmp + i) <= smaller) { // *(nums_tmp + i) is between smaller and smallest
            smaller = *(nums_tmp + i);
        }
    }
    
    /* The logic is same as 
     * "biggest * bigger * big > biggest * smaller * smallest ?
     * biggest * bigger * big : biggest * smaller * smallest"
     */
    /*
    if (pos_cnt >= 3 || (neg_cnt >= 2 && pos_cnt >= 1)) {
        i = biggest * bigger * big;
        j = biggest * smaller * smallest;
        result = i > j ? i : j;
    } else if (neg_cnt >= 3 || (pos_cnt >= 2 && neg_cnt >= 1)) {
        if (zero_cnt >= 1) {
            result = 0;
        } else {
            result = biggest * bigger * big;
        }
    }
    */
    return biggest * bigger * big > biggest * smaller * smallest ? \
            biggest * bigger * big : biggest * smaller * smallest;
    
    return result;
}
