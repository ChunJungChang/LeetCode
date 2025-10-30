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
        
        // When both t1 and t2 is NULL return NULL
        if (!t1 && !t2) {
            return NULL;
        }
        
        // Construct Stack
        stack<TreeNode*> stack_t1, stack_t2, stack_result;
        
        // Construct result root node
        TreeNode* result_root = new TreeNode(0);
        
        // Init all Stack
        stack_t1.push(t1);
        stack_t2.push(t2);
        stack_result.push(result_root);
        
        // In-order traverse the tree and construct new tree
        while (!stack_result.empty()) {
            
            // Tmp variable
            TreeNode* result_node = stack_result.top();
            TreeNode* t1_node = stack_t1.top();
            TreeNode* t2_node = stack_t2.top();
            
            // Pop up all the top node in stack
            stack_t1.pop();
            stack_t2.pop();
            stack_result.pop();
            
            // Deal with mid node
            result_node -> val = ((t1_node == NULL) ? 0 : t1_node -> val ) +
                                 ((t2_node == NULL) ? 0 : t2_node-> val);
            
            // Deal with right node 
            if ( (t1_node && t1_node -> right) || 
                 (t2_node && t2_node-> right) ) {
                result_node -> right = new TreeNode(0);
                stack_result.push(result_node -> right);
                stack_t1.push(t1_node == NULL ? NULL : t1_node -> right);
                stack_t2.push(t2_node == NULL ? NULL : t2_node -> right);
            }
            
            // Deal with left node
            if ( (t1_node && t1_node-> left) || 
                 (t2_node && t2_node -> left) ) {
                result_node -> left = new TreeNode(0);
                stack_result.push(result_node -> left);
                stack_t1.push(t1_node == NULL ? NULL : t1_node -> left);
                stack_t2.push(t2_node == NULL ? NULL : t2_node -> left);
            }
        }
        
        return result_root;
    }
};
