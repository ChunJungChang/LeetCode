/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize == 0)
        return NULL;
    
    int mid = numsSize / 2;
    struct TreeNode* res = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    res->val = nums[mid];
    res->left = sortedArrayToBST(nums, mid);
    res->right = sortedArrayToBST(nums + mid + 1, numsSize - mid - 1);
    
    return res;
}
