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

struct TreeNode** createTrees(int low, int high, int *size) {
    struct TreeNode **ret = NULL;

    if (low > high) {
        ret = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
        *ret = NULL;
        *size = 1;

        return ret;
    }

    /**
     * 1 <= n <= 8, the maximum number of nodes is 1430 when n = 8.
     */
    ret = (struct TreeNode**)malloc(1430 * sizeof(struct TreeNode*));
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
