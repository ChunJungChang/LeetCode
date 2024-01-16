int numTrees(int n) {
    int *arr = NULL, ret = 0, i = 0, j = 0;

    if (n == 0) {
        return ret;
    }

    if (n > 0) {
        arr = (int*)calloc(n + 1, sizeof(int));
    }

    arr[0] = 1;
    for (i = 1; i <= n; i++) {
        for (j = 0; j < i; j ++) {
            /**
              * arr[j]: left subtree.
              * arr[i - j - 1]: right subtree, 1 means root.
              */
            arr[i] += arr[j] * arr[i - j - 1];
            /*
            printf("arr[%d] += arr[%d] * arr[%d]: ", i, j, i - j - 1);
            printf("%d += %d * %d\n", arr[i], arr[j], arr[i - j - 1]);
            */
        }
    }

    ret = arr[n];

    if (arr) {
        free(arr);
        arr = NULL;
    }

    return ret;
}
