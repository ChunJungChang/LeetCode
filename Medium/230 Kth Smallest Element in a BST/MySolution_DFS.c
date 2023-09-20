/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int inorderTraversal(struct TreeNode *root, int k, int *nodeCnt) {
    int leftCnt = 0, rightCnt = 0, cnt = 0, ret = -1;

    if (!root) {
        return -1; /* Initial value, 0 <= root->val <=10^4 */
    }

    ret = inorderTraversal(root->left, k, nodeCnt);
    *nodeCnt += 1; /* Count current node */
    if (ret > -1) {
        /* Already find kth node, do nothing */
    } else if (*nodeCnt == k) {
        ret = root->val;
    } else {
        ret = inorderTraversal(root->right, k, nodeCnt);
    }

    return ret;
}

int kthSmallest(struct TreeNode* root, int k){
    int nodeCnt = 0, res = 0;

    res = inorderTraversal(root, k, &nodeCnt);

    return res;
}
