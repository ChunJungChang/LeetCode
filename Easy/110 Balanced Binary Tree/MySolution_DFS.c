/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <math.h>

int treeDepth(struct TreeNode* root) {
    int leftDepth = 0, rightDepth = 0;
    
    if (!root) {
        return 0;
    }
    
    leftDepth = treeDepth(root->left);
    rightDepth = treeDepth(root->right);
    
    return 1 + (leftDepth >= rightDepth ? leftDepth : rightDepth);
}

bool isBalanced(struct TreeNode* root) {
    int leftDepth = 0, rightDepth = 0, diffDepth = 0;
    bool leftRes = false, rightRes = false;
    
    if (!root) {
        return true;
    }
    
    leftRes = isBalanced(root->left);
    rightRes = isBalanced(root->right);
    if (!leftRes || !rightRes) {
        return false;
    }
    
    leftDepth = treeDepth(root->left);
    rightDepth = treeDepth(root->right);
    diffDepth = abs(leftDepth - rightDepth);
    
    return diffDepth <= 1 ? true : false;
}
