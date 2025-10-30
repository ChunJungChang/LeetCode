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
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int returnSizeLeft = 0, returnSizeRight = 0, i = 0;
    int *retLeft = NULL, *retRight = NULL, *ret = NULL;
    
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    
    retLeft = postorderTraversal(root->left, &returnSizeLeft);
    retRight = postorderTraversal(root->right, &returnSizeRight);
    
    *returnSize = returnSizeLeft + returnSizeRight + 1;
    ret = (int*)calloc(*returnSize, sizeof(int));
    
    for (i = 0; i < returnSizeLeft; i++) {
        ret[i] = retLeft[i];
    }
    for (i = returnSizeLeft; i < *returnSize - 1; i++) {
        ret[i] = retRight[i - returnSizeLeft];
    }
    ret[*returnSize - 1] = root->val;
    
    if (retLeft) {
        free(retLeft);
    }
    if (retRight) {
        free(retRight);
    }
    
    return ret;
}
