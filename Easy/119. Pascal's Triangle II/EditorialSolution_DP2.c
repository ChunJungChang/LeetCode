int* getRow(int rowIndex, int* returnSize) {
    int* prev = (int*)malloc((rowIndex + 1) * sizeof(int));
    int* curr = (int*)malloc((rowIndex + 1) * sizeof(int));
    prev[0] = 1;
    *returnSize = 1;
    for (int i = 1; i <= rowIndex; i++) {
        curr[0] = curr[i] = 1;
        for (int j = 1; j < i; j++) curr[j] = prev[j - 1] + prev[j];
        memcpy(prev, curr, (i + 1) * sizeof(int));
        *returnSize = i + 1;
    }
    free(curr);
    return prev;
}
