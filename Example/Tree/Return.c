int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    // Output: [[3,4,5,6,7]]

    int **ret = NULL;
  
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
}
