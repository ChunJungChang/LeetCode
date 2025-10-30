/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* prev = NULL;

bool isValidBSTHelper(struct TreeNode* root){
    if (!root) {
        return true;
    }

    if (isValidBSTHelper(root->left) == false) {
        return false;
    }

    if (prev && root->val <= prev->val) {
        return false;
    }

    prev = root;

    return isValidBSTHelper(root->right);
}

bool isValidBST(struct TreeNode* root){
    bool ret = false;

    ret = isValidBSTHelper(root);
    
    prev = NULL;

    return ret;
}
