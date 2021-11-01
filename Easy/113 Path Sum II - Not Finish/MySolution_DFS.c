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
    int i = 0;
    int *column = NULL, **res_left = NULL, **res_right = NULL, **res= NULL;

    depth += 1;
    
    if (!root) {
        depth -= 1;
        
        *returnSize = 0;
        *returnColumnSizes = NULL;
        
        return res;
    }
    
    path_record[depth - 1] = root->val;
    
    targetSum -= root->val;
    
    if (targetSum == 0 && !root->left && !root->right) {
        returnSize = calloc(1, sizeof(int));
        *returnSize = 1;

        returnColumnSizes = (int**)calloc(1, sizeof(int*));
        *returnColumnSizes = (int*)calloc(1, sizeof(int));
        *returnColumnSizes = depth;

        res = (int**)calloc(1, sizeof(int*));
        *res = (int*)calloc(depth, sizeof(int));
        for (i = 0; i < depth; i++) {
            res[0][i] = path_record[i];
            printf("res[0][%d]: %d \n", i, res[0][i]);
        }

        depth -= 1;
        return res;
    } else {
        res_left = pathSum(root->left, targetSum, returnSize, returnColumnSizes);
        res_right = pathSum(root->right, targetSum, returnSize, returnColumnSizes);
        
        
    }
    
    depth -= 1;
    return returnColumnSizes;
}
