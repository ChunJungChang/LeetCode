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
    int dep = 0;
    
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int Ldep = 1 + maxDepth(root->left);
        int Rdep = 1 + maxDepth(root->right);
        
        if (Ldep > Rdep)
            dep = Ldep;
        else
            dep = Rdep;
            
        return dep;
    }
};
