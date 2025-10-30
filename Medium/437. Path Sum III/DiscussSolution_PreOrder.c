/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 /**
 * https://leetcode.com/problems/path-sum-iii/discuss/141424/Python-step-by-step-walk-through.-Easy-to-understand.-Two-solutions-comparison.-%3A-)
 */
void preOrder(struct TreeNode *node, int depth, int sum, int *res, int *pathRecord) {
    if (!node) {
        return;
    }
    
    pathRecord[depth] = pathRecord[depth - 1] + node->val;
    for (int i = 0 ; i < depth ; i++) {
        if (pathRecord[depth] - pathRecord[i] == sum) {
            (*res)++;
        }
    }
        
    preOrder(node->left, depth + 1, sum, res, pathRecord);
    preOrder(node->right, depth + 1, sum, res, pathRecord);
}

int pathSum(struct TreeNode *root, int sum) {
    int res = 0;
    int pathRecord[1001] = {0};

    pathRecord[0] = 0;
    
    preOrder(root, 1, sum, &res, pathRecord);

    return res;
}
