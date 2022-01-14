/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int depth = 0;
int path_record[5000];

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes) {
    int i = 0, j = 0, returnSize_left = 0, returnSize_right = 0, size = 0;
    int *returnColumnSizes_left = NULL, *returnColumnSizes_right = NULL,
        **res_left = NULL, **res_right = NULL, **res= NULL;
    
    depth += 1;
    *returnSize = size;
    
    if (!root) {
        depth -= 1;

        return NULL;
    }
    
    path_record[depth - 1] = root->val;
    targetSum -= root->val;

    if (targetSum == 0 && !(root->left) && !(root->right)) {
        size = 1;

        *returnColumnSizes = (int*)calloc(1, sizeof(int));
        **returnColumnSizes = depth;

        res = (int**)calloc(1, sizeof(int*));
        *res = (int*)calloc(depth, sizeof(int));
        for (i = 0; i < depth; i++) {
            res[0][i] = path_record[i];
            /*
            printf("Leaf, res[0][%d]: %d \n", i, res[0][i]);
            */
        }
    } else {
        if (root->left) {
            res_left = pathSum(root->left, targetSum, &returnSize_left, &returnColumnSizes_left);
        }
        size += returnSize_left;
        if (root->right) {
            res_right = pathSum(root->right, targetSum, &returnSize_right, &returnColumnSizes_right);
        }
        size += returnSize_right;
        
        /*
        printf("Non-Leaf, root->val: %d\n", root->val);
        */
        
        if (size > 0) {
            *returnColumnSizes = (int*)calloc(size, sizeof(int));
            res = (int**)calloc(size, sizeof(int*));

            for (i = 0; i < returnSize_left; i++) {
                (*returnColumnSizes)[i] = returnColumnSizes_left[i];
                res[i] = (int*)calloc(returnColumnSizes_left[i], sizeof(int));
                for (j = 0; j < returnColumnSizes_left[i]; j++) {
                    res[i][j] = res_left[i][j];
                    /*
                    printf("Non-Leaf left, res[%d][%d]: %d \n", i, j, res[i][j]);
                    */
                }
            }
            for (i = 0; i < returnSize_right; i++) {
                (*returnColumnSizes)[returnSize_left + i] = returnColumnSizes_right[i];
                res[returnSize_left + i] = (int*)calloc(returnColumnSizes_right[i], sizeof(int));
                for (j = 0; j < returnColumnSizes_right[i]; j++) {
                    res[returnSize_left + i][j] = res_right[i][j];
                    /*
                    printf("Non-Leaf right, res[%d][%d]: %d \n", returnSize_left + i, j, res[returnSize_left + i][j]);
                    */
                }
            }
            
            if (returnColumnSizes_left) {
                free(returnColumnSizes_left);
            }
            if (returnSize_left) {
                for (i = 0; i < returnSize_left; i++) {
                    free(res_left[i]);
                }
            }
            if (returnColumnSizes_right) {
                free(returnColumnSizes_right);
            }
            if (returnSize_right) {
                for (i = 0; i < returnSize_right; i++) {
                    free(res_right[i]);
                }
            }
        }
    }
    
    depth -= 1;
    *returnSize = size;
    /*
    printf("===============\n");
    */
    return res;
}
