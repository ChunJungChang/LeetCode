/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/* Time complexity : O(N) */
int computeDepth(struct TreeNode *root) {
    int depth = 0;

    while (root->left) {
        root = root->left;
        depth++;
    }

    return depth;
}

bool exists(int idx, int depth, struct TreeNode* root) {
    int leftIdx = 0, rightIdx = 0, pivot = 0, i = 0;

    leftIdx = 0;
    rightIdx = (1 << depth) - 1;

    for (i = 0; i < depth; i++) {
        pivot = leftIdx + (rightIdx - leftIdx) / 2;
        //printf("Range: %d ~ %d, exists pivot: %d\n", leftIdx, rightIdx, pivot);
        if (idx <= pivot) {
            root = root->left;
            rightIdx = pivot;
            //printf("main pivot: %d is in the left side %d ~ %d\n", idx, leftIdx, rightIdx);
        } else {
            root = root->right;
            leftIdx = pivot + 1;
            //printf("main pivot: %d in the right side %d ~ %d\n", idx, leftIdx, rightIdx);
        }
    }

     return root != NULL;
 }

int countNodes(struct TreeNode* root){
    int depth = 0, leftIdx = 0, rightIdx = 0, pivot = 0, ret = 0;

    if (!root) {
        return ret;
    }

    depth = computeDepth(root);
    if (depth == 0) {
        ret = 1;
        return ret;
    }

    leftIdx = 0;
    rightIdx = (1 << depth) - 1;
    while (leftIdx <= rightIdx) {
         /* Try to find the node which Idx is pivot in the last level */
        pivot = leftIdx + (rightIdx - leftIdx) / 2;
        //printf("main pivot: %d\n", pivot);
        if (exists(pivot, depth, root)) {
            leftIdx = pivot + 1;
        } else {
            rightIdx = pivot - 1;
        }
        //printf("----------\n");
    }

    return (1 << depth) - 1 + leftIdx;
}
