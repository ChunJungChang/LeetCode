/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 #include <math.h>

bool isBalancedWithHeight(struct TreeNode* root, int *ptrHeight) {
    int leftHeight = 0, rightHeight = 0, diffHeight = 0;
    bool leftRes = false, rightRes = false;

    if (!root) {
        *ptrHeight = 0;

        return true;
    }
    
    if (!isBalancedWithHeight(root->left, &leftHeight)) {
        return false;
    }
    
    if (!isBalancedWithHeight(root->right, &rightHeight)) {
        return false;
    }
    
    diffHeight = abs(leftHeight - rightHeight);
    if (diffHeight > 1) {
        return false;
    }
    
    *ptrHeight = 1 + (leftHeight >= rightHeight ? leftHeight : rightHeight);
    return true;
}

bool isBalanced(struct TreeNode* root) {
    int height = 0;
    
    return isBalancedWithHeight(root, &height);
}
