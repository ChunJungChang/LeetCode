/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * 96. Unique Binary Search Trees
 */
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

struct TreeNode** createTrees(int low, int high, int *size) {
    struct TreeNode **ret = NULL;

    if (low > high) {
        ret = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
        *ret = NULL;
        *size = 1;

        return ret;
    }

    ret = (struct TreeNode**)malloc(numTrees(high - low + 1) * sizeof(struct TreeNode*));
    *size = 0;

    for (int i = low; i <= high; i++) {
        int leftTreesSize = 0, rightTreesSize = 0;

        struct TreeNode **leftTrees = createTrees(low, i - 1, &leftTreesSize);
        struct TreeNode **rightTrees = createTrees(i + 1, high, &rightTreesSize);

        for (int j = 0; j < leftTreesSize; j++) {
            for (int k = 0; k < rightTreesSize; k++) {
                ret[*size] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                ret[*size]->val = i;
                ret[*size]->left = leftTrees[j];
                ret[*size]->right = rightTrees[k];
                *size += 1;
            }
        }
    }

    /* Todo: Free leftTrees and rightTrees. */

    return ret;
}

struct TreeNode** generateTrees(int n, int* returnSize){
    struct TreeNode **ret = NULL;

    ret = createTrees(1, n, returnSize);

    return ret;
}
