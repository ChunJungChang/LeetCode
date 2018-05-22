/**
  * Return an array of size *returnSize.
  * Note: The returned array must be malloced, assume caller calls free().
  */
int* selfDividingNumbers(int left, int right, int* returnSize) {
    int i = left, j = right, tmp = 0, div = 0, rem = 0;
    bool div_self = true;
    int *res = malloc(sizeof(int));
    *returnSize = 0;
    
    for (i ; i <= right ; i++) {
        tmp = i;
        div_self = true;
        
        do {
            div = tmp / 10;
            rem = tmp % 10;
            
            if (rem == 0 || i % rem != 0) {
                div_self = false;
                break;
            }
            
            tmp /= 10;
        } while (div != 0);
        
        if (div_self) {
            res = realloc(res, ((*returnSize) + 1) * sizeof(int));
            res[(*returnSize)++] = i;
        }
    }
    
    return res;
}
