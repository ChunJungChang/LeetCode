/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* DFS(struct TreeNode* root, int* sumPtr) {
    struct TreeNode *leftChild = NULL, *doNotCare = NULL;
    
    if (!root || (!root->left && !root->right)) {
        return root;
    }
    
    leftChild = DFS(root->left, sumPtr);
    if (leftChild && (!leftChild->left && !leftChild->right)) {
        *sumPtr += leftChild->val;
    }
    
    doNotCare = DFS(root->right, sumPtr);
    
    return root;
}

int sumOfLeftLeaves(struct TreeNode* root) {
    int sum = 0;
    
    if (!root || (!root->left && !root->right)) {
        return sum;
    }
    
    DFS(root, &sum);
    
    return sum;
}
