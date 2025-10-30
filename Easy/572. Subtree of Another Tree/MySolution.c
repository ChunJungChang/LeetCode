/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool sameTree(struct TreeNode* s, struct TreeNode* t) {
    if (!s && !t) {
        return true;
    } else if ((!s == t) || (s == !t)) {
        return false;
    } else if (s->val != t->val) {
        return false;
    } else {
        return sameTree(s->left, t->left) && sameTree(s->right, t->right);
    }
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
    if (!s) {
        return false;
    }
    
    if (s->val == t->val) {
        if (sameTree(s, t)) {
            return true;
        }
    }

    return isSubtree(s->left, t) || isSubtree(s->right, t);
}
