/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int nodeCnt(struct TreeNode* root) {
    if (!root) {
        return 0;
    }
    
    return 1 + nodeCnt(root->left) + nodeCnt(root->right);
}

void BST2Tbl(struct TreeNode* root, int* valTbl, int* idx) {
    if (!root) {
        return;
    }
    
    BST2Tbl(root->left, valTbl, idx);
    valTbl[(*idx)++] = root->val;
    BST2Tbl(root->right, valTbl, idx);
}

bool findTarget(struct TreeNode* root, int k) {
    int i = 0, j = 0, idx = 0, size = 0,
        *valTbl = NULL, findVal = 0;
    
    if (!root) {
        return false;
    }
    
    size = nodeCnt(root);
    valTbl = (int*)malloc(size * sizeof(int));
    BST2Tbl(root, valTbl, &idx);
    
    for (i = 0 ; i < size ; i++) {
        findVal = k - valTbl[i];
        for (j = i + 1 ; j < size ; j++) {
            if (findVal == valTbl[j]) {
                free(valTbl);
                return true;
            }
        }
    }
    
    free(valTbl);
    return false;
}
