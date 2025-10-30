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
        queue<TreeNode*> treeq;
        
        if (root == NULL) {
            return true;
        }
        
        treeq.push(root);
        while(!treeq.empty()) {
            int n = treeq.size();
            vector<int> v;
            v.resize(n * 2);
            int v_idx = 0;
            for (int i = 0 ; i < n ; i++) {
                TreeNode* cur = treeq.front();
                treeq.pop();
                if (cur->left) {
                    treeq.push(cur->left);
                    v[v_idx] = cur->left->val;
                }
                v_idx++;
                if (cur->right) {
                    treeq.push(cur->right);
                    v[v_idx] = cur->right->val;
                }
                v_idx++;
            }
            
            for (int i = 0 ; i < n ; i++) {
                if (v[i] != v[n * 2 - i - 1])
                    return false;
            }
            v.clear();
        }
        
        return true;
    }
};
