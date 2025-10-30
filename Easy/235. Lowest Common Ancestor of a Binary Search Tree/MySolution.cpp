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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *result, *tmpP, *tmpQ;
        queue<TreeNode*> queueP, queueQ;
        
        if (root->val == p->val)
            queueP.push(root);
        else {
            tmpP = root;
            while (tmpP->val != p->val) {
                queueP.push(tmpP);
                if (tmpP->val > p->val) {
                    tmpP = tmpP->left;
                }
                else {
                    tmpP = tmpP->right;
                }
            }
            queueP.push(tmpP);
        }
        if (root->val == q->val)
            queueQ.push(root);
        else {
            tmpQ = root;
            while (tmpQ->val != q->val) {
                queueQ.push(tmpQ);
                if (tmpQ->val > q->val) {
                    tmpQ = tmpQ->left;
                }
                else {
                    tmpQ = tmpQ->right;
                }
            }
            queueQ.push(tmpQ);
        }
        
        while (queueP.front() == queueQ.front()) {
            result = queueP.front();
            queueP.pop();
            queueQ.pop();
        }
        
        return result;
    }
};
