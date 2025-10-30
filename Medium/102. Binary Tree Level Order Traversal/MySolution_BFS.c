/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    /*
    // Output: [[3,4,5,6,7]]

    *returnSize = 1;
    returnColumnSizes[0] = (int *)malloc(1 * sizeof(int));
    returnColumnSizes[0][0] = 5;
    ret = (int**)malloc(1 * sizeof(int*));
    ret[0] = (int *)malloc(5 * sizeof(int));
    ret[0][0] = 3;
    ret[0][1] = 4;
    ret[0][2] = 5;
    ret[0][3] = 6;
    ret[0][4] = 7;
    
    return ret;
    */

    int level_size = 0;
    struct TreeNode **level_node = NULL;
    int **ret = NULL;

    *returnSize = 0;
    *returnColumnSizes = NULL;

    if (!root) {
        return ret;
    }

    level_size++;
    level_node = (struct TreeNode **)malloc(level_size * sizeof(struct TreeNode *));
    level_node[0] = root;

    while (level_size != 0) {
        int node_cnt = level_size;
        level_size = 0;

        *returnSize += 1;
        //printf("returnSize: %d, ", *returnSize);
        *returnColumnSizes = (int *)realloc(*returnColumnSizes, *returnSize * sizeof(int));
        (*returnColumnSizes)[*returnSize - 1] = node_cnt;
        //printf("returnColumnSizes: %d, ", (*returnColumnSizes)[*returnSize - 1]);

        ret = (int **)realloc(ret, *returnSize * sizeof(int *));
        ret[*returnSize - 1] = (int *)malloc(node_cnt * sizeof(int));

        struct TreeNode **node = (struct TreeNode **)malloc(node_cnt * sizeof(struct TreeNode *));
        //printf("ret[%d] ", *returnSize - 1);
        for (int i = 0; i < node_cnt; i++) {
            node[i] = level_node[i];
            level_node[i] = NULL;

            ret[*returnSize - 1][i] = node[i]->val;
            //printf("%d ", ret[*returnSize - 1][i]);
        }
        //printf("\n");
        free(level_node);

        level_node = (struct TreeNode **)malloc(2 * node_cnt * sizeof(struct TreeNode *));
        for (int i = 0; i < node_cnt; i++) {
            struct TreeNode *ptr = node[i];
            node[i] = NULL;

            if (ptr->left) {
                level_node[level_size++] = ptr->left;
            }
            if (ptr->right) {
                level_node[level_size++] = ptr->right;
            }
        }
        free(node);
    }
    free(level_node);

    return ret;
}
