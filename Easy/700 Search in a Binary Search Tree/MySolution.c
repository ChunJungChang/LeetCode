/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (!root) {
        return NULL;
    }
    
    struct TreeNode *node = NULL;
    
    if (root->val < val) {
        node = searchBST(root->right, val);
    } else if (root->val > val) {
        node = searchBST(root->left, val);
    } else {
        node = root;
    }
    
    return node;
}
