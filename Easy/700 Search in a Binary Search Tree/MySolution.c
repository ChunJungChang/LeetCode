/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/* Your runtime beats 100.00 % of c submissions. */
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (!root) {
        return NULL;
    }
    
    if (root->val < val) {
        return searchBST(root->right, val);
    } else if (root->val > val) {
        return searchBST(root->left, val);
    } else {
        return root;
    }
}
