/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int minDepth(struct TreeNode* root){
    int leftDepth = 0, rightDepth = 0;
    
    if (!root) {
        return 0;
    }
    
    leftDepth = minDepth(root->left);
    rightDepth = minDepth(root->right);
    
    if (leftDepth == 0 && rightDepth == 0) {
        return 1;
    } else if (rightDepth == 0 && leftDepth > 0) {
        return leftDepth + 1;
    } else if (leftDepth == 0 && rightDepth > 0) {
        return rightDepth + 1;
    } else if (leftDepth < rightDepth) {
        return leftDepth + 1;
    } else {
        return rightDepth + 1;
    }
}
