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
    queue<TreeNode*> level;
    
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return NULL;
        else
            level.push(root);
            
        while(!level.empty()) {
            int n = level.size();
            for(int i = 0;i < n;i++) {
                TreeNode* cur = level.front();
                level.pop();
                if (cur->left != NULL)
                    level.push(cur->left);
                if (cur->right != NULL)
                    level.push(cur->right);
                swap(cur->left, cur->right);
            }
        }
        return root;
    }
};
