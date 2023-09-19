struct TreeNode** inorderTraversal(struct TreeNode* root, int* returnSize){
    int returnSizeLeft = 0, returnSizeRight = 0, i = 0;
    struct TreeNode **retLeft = NULL, **retRight = NULL, **ret = NULL;
    
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    
    retLeft = inorderTraversal(root->left, &returnSizeLeft);
    retRight = inorderTraversal(root->right, &returnSizeRight);
    
    *returnSize = returnSizeLeft + returnSizeRight + 1;
    ret = (struct TreeNode**)calloc(*returnSize, sizeof(struct TreeNode*));
    
    for (i = 0; i < returnSizeLeft; i++) {
        ret[i] = retLeft[i];
    }
    ret[returnSizeLeft] = root;
    for (i = returnSizeLeft + 1; i < *returnSize; i++) {
        ret[i] = retRight[i - (returnSizeLeft + 1)];
    }
    
    if (retLeft) {
        free(retLeft);
    }
    retLeft = NULL;
    if (retRight) {
        free(retRight);
    }
    retRight = NULL;
    
    return ret;
}

void bSTIterator(struct TreeNode* root) {
    int returnSize = 0, i = 0;
    struct TreeNode **res = NULL;

    res = inorderTraversal(root, &returnSize);
    for (i = 0; i < returnSize; i++) {
        printf("%d ", res[i]->val);
    }
    printf("\n");
}
