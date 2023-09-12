/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isValidBSTHelper(struct TreeNode* root, int* returnSize, int **inorderList){
    int returnSizeLeft = 0, returnSizeRight = 0, i = 0;
    int *leftInorderList = NULL, *rightInorderList = NULL;
    bool ret = true, retLeft = true, retRight = true;
    
    if (!root) {
        *returnSize = 0;
        return true;
    }

    retLeft = isValidBSTHelper(root->left, &returnSizeLeft, &leftInorderList);
    retRight = isValidBSTHelper(root->right, &returnSizeRight, &rightInorderList);
    /*
    printf("root->val: %d\n", root->val);
    printf("leftInorderList: ");
    for (i = 0; i < returnSizeLeft; i++) {
        printf("%d ", leftInorderList[i]);
    }
    printf("\n");
    printf("rightInorderList: ");
    for (i = 0; i < returnSizeRight; i++) {
        printf("%d ", rightInorderList[i]);
    }
    printf("\n");
    */
    
    *returnSize = returnSizeLeft + returnSizeRight + 1;
    *inorderList = (int*)calloc(*returnSize, sizeof(int));
    /*
    printf("*returnSize: %d = returnSizeLeft: %d + returnSizeRight: %d + 1\n", *returnSize, returnSizeLeft, returnSizeRight);
    */
    
    for (i = 0; i < returnSizeLeft; i++) {
        (*inorderList)[i] = leftInorderList[i];
    }
    if (leftInorderList) {
        if (leftInorderList[returnSizeLeft - 1] >= root->val) {
            ret = false;
        }

        free(leftInorderList);
        leftInorderList = NULL;
    }
    /*
    printf("inorderListLeft: ");
    for (i = 0; i < returnSizeLeft; i++) {
        printf("%d ", (*inorderList)[i]);
    }
    printf("\n");
    */

    (*inorderList)[returnSizeLeft] = root->val;
    /*
    printf("inorderListRoot: ");
    printf("%d ", (*inorderList)[returnSizeLeft]);
    printf("\n");
    */

    for (i = returnSizeLeft + 1; i < *returnSize; i++) {
        (*inorderList)[i] = rightInorderList[i - (returnSizeLeft + 1)];
    }
    if (rightInorderList) {
        if (root->val >= rightInorderList[0]) {
            ret = false;
        }

        free(rightInorderList);
        rightInorderList = NULL;
    }
    /*
    printf("inorderListRight: ");
    for (i = returnSizeLeft + 1; i < *returnSize; i++) {
        printf("%d ", (*inorderList)[i]);
    }
    printf("\n");
    */
    
    /*
    printf("inorderList: ");
    for (i = 0; i < *returnSize; i++) {
        printf("%d ", (*inorderList)[i]);
    }
    printf("\n");
    printf("retLeft: %s ,retRight: %s, ret: %s\n\n",
           retLeft ? "true" : "fasle", retRight ? "true" : "fasle", (ret & retLeft & retRight) ? "true" : "fasle");
    */

    return (ret & retLeft & retRight);
}

bool isValidBST(struct TreeNode* root){
    int returnSize = 0, *inorderList = NULL;
    bool ret = true;

    ret = isValidBSTHelper(root, &returnSize, &inorderList);

    free(inorderList);

    return ret;
}
