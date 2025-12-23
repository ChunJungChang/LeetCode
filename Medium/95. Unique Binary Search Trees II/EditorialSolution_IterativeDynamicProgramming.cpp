/*
 * For example, n = 3
 *
 * dp[1][1] = 1, dp[2][2] = 1, dp[3][3] = 1
 *
 * numberOfNodes = 2 => start value 1 to end value 2: (1, 2), start value 2 to end value 3: (2, 3)
 * numberOfNodes = 3 => start value 1 to end value 3: (1, 2, 3)
 *
 * For numberOfNodes = 2
 * i means root.
 * (1, 2) => i = 1: [1, null, 2]
 *           i = 2: [2, 1, null]
 *        => dp[1][2] = [[1, null, 2], [2, 1, null]]
 * (2, 3) => i = 2: [2, null, 3]
 *           i = 3: [3, 2, null]
 *        => dp[2][3] = [[2, null, 3], [3, 2, null]]
 *
 * For numberOfNodes = 3
 * (1, 2, 3) => i = 1, right subtree is (2, 3): [1, null, 2, null, 3], [1, null, 3, 2, null]
 *              i = 2: [2, 1, 3]
 *              i = 3, left subtree is (1, 2): [3, 1, null, 2], [3, 2, 1, null]
 *           => dp[1][3] = [[1, null, 2, null, 3], [1, null, 3, 2, null], [2, 1, 3], [3, 1, null, 2], [3, 2, 1, null]]
 */

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<TreeNode*>>> dp(
            n + 1, vector(n + 1, vector<TreeNode*>(0)));
        for (int i = 1; i <= n; i++) {
            dp[i][i].push_back(new TreeNode(i));
        }

        for (int numberOfNodes = 2; numberOfNodes <= n; numberOfNodes++) {
            for (int start = 1; start <= n - numberOfNodes + 1; start++) {
                int end = start + numberOfNodes - 1;
                for (int i = start; i <= end; i++) {
                    vector<TreeNode*> leftSubtrees =
                        i - 1 >= start ? dp[start][i - 1]
                                       : vector<TreeNode*>({NULL});
                    vector<TreeNode*> rightSubtrees =
                        i + 1 <= end ? dp[i + 1][end]
                                     : vector<TreeNode*>({NULL});

                    for (auto left : leftSubtrees) {
                        for (auto right : rightSubtrees) {
                            TreeNode* root = new TreeNode(i, left, right);
                            dp[start][end].push_back(root);
                        }
                    }
                }
            }
        }
        return dp[1][n];
    }
};
