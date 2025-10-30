/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int heightOfBinaryTree(struct TreeNode* root) {
    int leftHeight = 0, rightHeight = 0, height = 0;
    
    if (!root) {
        return 0;
    }
    
    leftHeight = heightOfBinaryTree(root->left);
    rightHeight = heightOfBinaryTree(root->right);
    
    height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    
    return height;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int leftHeight = 0, rightHeight = 0, passRootDiameter = 0;
    int leftDiameter = 0, rightDiameter = 0, maxDiameterOfSubTree = 0;
    
    if (!root) {
        return 0;
    }
    
    leftHeight = heightOfBinaryTree(root->left);
    rightHeight = heightOfBinaryTree(root->right);
    passRootDiameter = leftHeight + rightHeight;
    
    leftDiameter = diameterOfBinaryTree(root->left);
    rightDiameter = diameterOfBinaryTree(root->right);
    maxDiameterOfSubTree = (leftDiameter > rightDiameter ? leftDiameter : rightDiameter);
    
    if (passRootDiameter > maxDiameterOfSubTree) {
        return passRootDiameter;
    } else {
        return maxDiameterOfSubTree;
    }
}
