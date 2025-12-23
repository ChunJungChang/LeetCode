/*
 * We create a 2D list dp[n + 1] where dp[i] will store a list of all BSTs with i nodes having values from 1 to i. dp[n] would be the answer to the problem. Similar to the above approach, we will move in bottom to top manner.
 * We push a null node (empty tree) to dp[0] which acts as the base case.
 * To get the list of root nodes for all possible BSTs with numberOfNodes nodes, we would split the numberOfNodes nodes with i - 1 nodes with values 1 to i - 1 in the left subtree, a root node with value i and the remaining numberOfNodes - i nodes with values i + 1 to numberOfNodes in the right subtree where 1 <= i <= numberOfNodes. Note that we do not need the starting of the range here, unlike the previous approach. It is always 1.
 * However, you may realize that dp[i - 1] will give all the BSTs having values from 1 to i - 1 which is exactly what we want but dp[numberOfNodes - i] will give all the BSTs having values from 1 to numberOfNodes - i which isn't what we want. We want the right subtree to have numberOfNodes - i nodes but the range of nodes should be from i + 1 to numberOfNodes. If we add the offset (i + 1) - 1 = i to all the nodes, it would solve this as we would now have trees with numberOfNodes - i nodes from values i + 1 to numberOfNodes. Let us form the BSTs now.
 * Now, let's set the right child of root. We know every element in dp[numberOfNodes - i] is a root node that stores a BST with numberOfNodes - 1 nodes having values from 1 to numberOfNodes - i. To set the right child of root, we create a new tree exactly similar to the tree stored by an element of dp[numberOfNodes - i] but increment all the node values of the new tree by i. We then set the right child of root to this newer tree.
 * The required tree with i offset can be created by using a recursive function clone in which we pass a TreeNode node which corresponds to an element in dp[numberOfNodes - i] and an integer offset. We create a new TreeNode clonedNode with value node.val + offset. We then recursively set the left and the right child of clonedNode by performing clonedNode.left = clone(node.left, offset) and clonedNode.right = clone(node.right, offset). Finally, return clonedNode.
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>> dp(n + 1);
        dp[0].push_back(NULL);

        for (int numberOfNodes = 1; numberOfNodes <= n; numberOfNodes++) {
            for (int i = 1; i <= numberOfNodes; i++) {
                int j = numberOfNodes - i;
                for (auto left : dp[i - 1]) {
                    for (auto right : dp[j]) {
                        TreeNode* root = new TreeNode(i, left, clone(right, i));
                        dp[numberOfNodes].push_back(root);
                    }
                }
            }
        }
        return dp[n];
    }

private:
    TreeNode* clone(TreeNode* node, int offset) {
        if (node == NULL) {
            return NULL;
        }
        TreeNode* clonedNode = new TreeNode(node->val + offset);
        clonedNode->left = clone(node->left, offset);
        clonedNode->right = clone(node->right, offset);
        return clonedNode;
    }
};
