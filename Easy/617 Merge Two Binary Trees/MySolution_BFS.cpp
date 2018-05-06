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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        queue<TreeNode*> t1_list, t2_list, res_list;
        TreeNode *res_root = NULL;
        
        if (!t1 && !t2) {
            return res_root;
        } else if (t1 && !t2) {
            return t1;
        } else if (!t1 && t2) {
            return t2;
        }
        
        t1_list.push(t1);
        t2_list.push(t2);
        res_root = new TreeNode(0);
        res_list.push(res_root);
        
        while (!res_list.empty()) {
            int loop_cnt = res_list.size();
            
            for (int i = 0 ; i < loop_cnt ; i++) {
                TreeNode *t1_cur = NULL, *t2_cur = NULL,
                            *tmp = NULL, *res_cur = NULL;
                
                t1_cur = t1_list.front();
                t1_list.pop();
                t2_cur = t2_list.front();
                t2_list.pop();
                res_cur = res_list.front();
                res_list.pop();
                
                if (!res_cur) {
                    continue;
                }

                if (t1_cur != NULL || t2_cur != NULL) {
                    res_cur->val = (t1_cur ? t1_cur->val : 0) + (t2_cur ? t2_cur->val : 0);
                }
                
                if ((t1_cur && t1_cur->left) || (t2_cur && t2_cur->left)) {
                    tmp = new TreeNode(0);
                    res_cur->left = tmp;
                    res_list.push(tmp);
                } else {
                    res_list.push(NULL);
                }
                if ((t1_cur && t1_cur->right) || (t2_cur && t2_cur->right)) {
                    tmp = new TreeNode(0);
                    res_cur->right = tmp;
                    res_list.push(tmp);
                } else {
                    res_list.push(NULL);
                }
                
                if (t1_cur) {
                    t1_list.push(t1_cur->left);
                    t1_list.push(t1_cur->right);
                } else {
                    t1_list.push(NULL);
                    t1_list.push(NULL);
                }
                if (t2_cur) {
                    t2_list.push(t2_cur->left);
                    t2_list.push(t2_cur->right);
                } else {
                    t2_list.push(NULL);
                    t2_list.push(NULL);
                }
            }
        }
        
        return res_root;
    }
};
