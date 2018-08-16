/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 void leafNode(int *idx, int *arr, struct TreeNode* root) {
    if (!root) {
        return;
    }
    
    if (!(root->left) && !(root->right)) {
        *(arr + (*idx)++) = root->val;
        
        return;
    }
    
    if (root->left) {
        leafNode(idx, arr, root->left);
    }
    if (root->right) {
        leafNode(idx, arr, root->right);
    }
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int root1_len = 0, root2_len = 0;
    int root1_leaf[100] = {0}, root2_leaf[100] = {0};
    int i = 0;
    
    leafNode(&root1_len, &root1_leaf, root1);
    leafNode(&root2_len, &root2_leaf, root2);
    if (root1_len != root2_len) {
        return false;
    } else {
        for (i = 0 ; i < root1_len ; i++) {
            if (root1_leaf[i] != root2_leaf[i]) {
                return false;
            }
        }
        
        return true;
    }
}
