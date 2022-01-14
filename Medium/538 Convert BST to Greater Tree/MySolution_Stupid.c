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

void DFS(struct TreeNode* root, int* valTbl, const int size) {
    int i = 0, sum = 0;
    
    if (!root) {
        return;
    }
    
    DFS(root->left, valTbl, size);
    DFS(root->right, valTbl, size);
    
    for (i = 0 ; i < size ; i++) {
        if (root->val < valTbl[i]) {
            sum += valTbl[i];
        }
    }
    root->val += sum;
}

struct TreeNode* convertBST(struct TreeNode* root) {
    int i = 0, j = 0, idx = 0, size = 0,
        *valTbl = NULL, findVal = 0;
    
    if (!root) {
        return false;
    }
    
    size = nodeCnt(root);
    valTbl = (int*)malloc(size * sizeof(int));
    BST2Tbl(root, valTbl, &idx);
    DFS(root, valTbl, size);
    
    free(valTbl);
    return root;
}
