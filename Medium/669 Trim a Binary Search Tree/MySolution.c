/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* trimBST(struct TreeNode* root, int L, int R) {
    if (!root) {
        return NULL;
    }
    
    if (L > root->val) {
        root = trimBST(root->right, L, R);
    } else if (root->val > R) {
        root = trimBST(root->left, L, R);
    }
    
    if (root) {
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
    }

    return root;
}
