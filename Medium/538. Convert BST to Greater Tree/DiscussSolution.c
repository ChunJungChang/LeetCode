/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void DFSFromRight(struct TreeNode* root, int* curSum) {
    struct TreeNode *leftTree = NULL, *rightTree = NULL;
    
    if (!root) {
        return;
    }
    
    DFSFromRight(root->right, curSum);
    root->val = root->val + *curSum;
    *curSum = root->val;
    DFSFromRight(root->left, curSum);
}

struct TreeNode* convertBST(struct TreeNode* root) {
    int sum = 0;
    
    DFSFromRight(root, &sum);
    
    return root;
}
