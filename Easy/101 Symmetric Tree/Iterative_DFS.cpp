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
        if (!root) {
            return true;
        }

        TreeNode *treeleft = root->left;
        TreeNode *treeright = root->right;
        stack<TreeNode*> treelefts;
        treelefts.push(root);
        stack<TreeNode*> treerights;
        treerights.push(root);

        while (treeleft || treeright || !treelefts.empty() || !treerights.empty()) {
            if ((treeleft && !treeright) || (!treeleft && treeright)) {
                return false;
            }

            if (treeleft && treeright) {
                if (treeleft->val != treeright->val) {
                    return false;
                }

                treelefts.push(treeleft);
                treeleft = treeleft->left;
                treerights.push(treeright);
                treeright = treeright->right;
            } else {
                treeleft = treelefts.top()->right;
                treelefts.pop();
                treeright = treerights.top()->left;
                treerights.pop();
            }
        }
        
        return true;
    }
};
