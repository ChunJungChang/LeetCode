/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isValidBSTHelper(struct TreeNode* root, long low, long high) {
    if (!root)
        return true;
    
    if (root->val <= low || root->val >= high)
        return false;
    
    return isValidBSTHelper(root->left, low, root->val) && isValidBSTHelper(root->right, root->val, high);
}

bool isValidBST(struct TreeNode* root){
    return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
}
