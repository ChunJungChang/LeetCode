/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int checkPath(struct TreeNode* root, int sum) {
    int rem = 0;
    /**
     * Need to consider overlap path.
     */
    int findPath = 0;
    
    if (!root) {
        return findPath;
    }
    
    rem = sum - root->val;
    if (rem == 0) {
        findPath = 1;
    }
    
    return (findPath + checkPath(root->left, rem) + checkPath(root->right, rem));
}

int pathSum(struct TreeNode* root, int sum) {
    if (!root) {
        return 0;
    }
    
    return (checkPath(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum));
}
