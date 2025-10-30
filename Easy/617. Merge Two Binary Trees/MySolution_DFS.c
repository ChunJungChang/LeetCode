/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
    struct TreeNode *res = NULL, *left_tree = NULL, *right_tree = NULL;
    
    if (t1 == NULL || t2 == NULL) {
        if (t1) {
            res = t1;
        } else if (t2) {
            res = t2;
        }
        
        return res;
    }
    
    left_tree = mergeTrees(t1->left, t2->left);
    right_tree = mergeTrees(t1->right, t2->right);
    
    res = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    res->val = t1->val + t2->val;
    res->left = left_tree;
    res->right = right_tree;
    
    return res;
}
