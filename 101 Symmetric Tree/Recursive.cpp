/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;

        return isSymmetric_help(root->left, root->right);
    }
    bool isSymmetric_help(TreeNode* treeleft, TreeNode* treeright) {
        if (treeleft == NULL && treeright == NULL)
            return true;
        else if ((treeleft == NULL && treeright != NULL) || (treeleft != NULL && treeright == NULL))
            return false;
        else if (treeleft->val != treeright->val)
            return false;
        else
            return isSymmetric_help(treeleft->left, treeright->right) && isSymmetric_help(treeleft->right, treeright->left);
    }
};
