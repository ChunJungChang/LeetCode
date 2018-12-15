/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    int mid = 0;
    int leftSize = 0;
    int *leftList = NULL;
    int rightSize = 0;
    int *rightList = NULL;
    struct TreeNode *res = NULL;
    int i = 0;
    
    if (numsSize == 0) {
        return res;
    }
    
    /*
     * mid is a index.
     */
    if (numsSize % 2 == 1) {
        mid = numsSize / 2;
    } else {
        mid = numsSize / 2 - 1;
    }
    res = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    res->val = nums[mid];
    
    leftSize = (mid - 1) - 0 + 1;
    leftList = (int*)malloc(sizeof(int) * leftSize);
    for (i = 0 ; i < leftSize ; i++) {
        leftList[i] = nums[i];
    }
    res->left = sortedArrayToBST(leftList, leftSize);
    
    rightSize = (numsSize - 1) - (mid + 1) + 1;
    rightList = (int*)malloc(sizeof(int) * rightSize);
    for (i = 0 ; i < rightSize ; i++) {
        rightList[i] = nums[i + (mid + 1)];
    }
    res->right = sortedArrayToBST(rightList, rightSize);
    
    if (leftList) {
        free(leftList);
    }
    if (rightList) {
        free(rightList);
    }
    
    return res;
}
