/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <math.h>

int* countBits(int n, int* returnSize) {
    int *ret = NULL, cnt = 0, i = 0, j = 0;

    *returnSize = n + 1;
    ret = (int*)calloc(*returnSize, sizeof(int));

    for (i = 0; i <= n; i++) {
        cnt = 0;

        for (j = 0; j <= log2(i); j++) {
             if ((i >> j & 1) == 1) {
                cnt += 1;
             }
        }

        ret[i] = cnt;
    }

    return ret;
}
