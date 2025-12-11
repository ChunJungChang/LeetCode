class Solution {
public:
    int depthFirstSearch(int n, int k, int rootVal) {
        int totalNodes = 0;

        if (n == 1) {
            return rootVal;
        }

        totalNodes = pow(2, n - 1);
        if (k <= totalNodes / 2) { /* Left sub-tree */
            int nextRootVal = (rootVal == 0) ? 0 : 1;
            
            return depthFirstSearch(n - 1, k, nextRootVal);
        } else { /* Right sub-tree */
            int nextRootVal = (rootVal == 0) ? 1 : 0;

            return depthFirstSearch(n - 1, k - (totalNodes / 2), nextRootVal);
        }
    }

    int kthGrammar(int n, int k) {

        return depthFirstSearch(n, k, 0);
    }
};
