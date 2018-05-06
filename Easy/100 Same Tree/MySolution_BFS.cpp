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
    bool tmpresult = true;
    queue<TreeNode*> tree1;
    queue<TreeNode*> tree2;
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((p == NULL) && (q == NULL))
            return true;
        
        tree1.push(p);
        tree2.push(q);
        while (!tree1.empty() && !tree2.empty()) {
            int n1 = tree1.size();
            int n2 = tree2.size();
            for (int i = 0;i < n1;i++) {
                TreeNode* cur1 = tree1.front();
                tree1.pop();
                TreeNode* cur2 = tree2.front();
                tree2.pop();
                if (cur1 == NULL || cur2 == NULL) {
                    tmpresult = false;
                }
                else if (cur1->val == cur2->val) {
                    if((cur1->left) && (cur2->left)) {
                        tree1.push(cur1->left);
                        tree2.push(cur2->left);
                    }
                    else if (((cur1->left == NULL) && (cur2->left != NULL)) || ((cur1->left != NULL) && (cur2->left == NULL))) {
                        tmpresult = false;
                    }
                    if((cur1->right) && (cur2->right)) {
                        tree1.push(cur1->right);
                        tree2.push(cur2->right);
                    }
                    else if (((cur1->right == NULL) && (cur2->right != NULL)) || ((cur1->right != NULL) && (cur2->right == NULL))) {
                        tmpresult = false;
                    }
                }
                else if (cur1->val != cur2->val) {
                    tmpresult = false;
                }
                
            }
        }
        return tmpresult;
    }
};
