/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode *leftRes = NULL, *rightRes = NULL;
    
    if (!root) {
        return NULL;
    }

    if (root == p || root == q) {
        return root;
    }

    leftRes = lowestCommonAncestor(root->left, p, q);
    rightRes = lowestCommonAncestor(root->right, p, q);

    if (leftRes && rightRes) {
        return root;
    } else if (leftRes) {
        return leftRes;
    } else if (rightRes) {
        return rightRes;
    } else {
        return NULL;
    }
}
