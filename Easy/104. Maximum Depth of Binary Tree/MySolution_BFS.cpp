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
    queue<TreeNode*> level;
    
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return dep;
        
        level.push(root);
        while (!level.empty()) {
            dep++;
            int n = level.size();
            for (int i = 0;i < n;i++) {
                TreeNode* cur = level.front();
                level.pop();
                if (cur->left) level.push(cur->left);
                if (cur->right) level.push(cur->right);
            }
        }
        return dep;
    }
};
