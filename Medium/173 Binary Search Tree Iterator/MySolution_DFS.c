/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct {
    int idx;
    int size; // -1: The Binary Search Tree is NULL.
    struct TreeNode **treeNodeInorder;
} BSTIterator;

struct TreeNode** inorderTraversal(struct TreeNode* root, int* returnSize){
    int returnSizeLeft = 0, returnSizeRight = 0, i = 0;
    struct TreeNode **retLeft = NULL, **retRight = NULL, **ret = NULL;
    
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    
    retLeft = inorderTraversal(root->left, &returnSizeLeft);
    retRight = inorderTraversal(root->right, &returnSizeRight);
    
    *returnSize = returnSizeLeft + returnSizeRight + 1;
    ret = (struct TreeNode**)calloc(*returnSize, sizeof(struct TreeNode*));
    
    for (i = 0; i < returnSizeLeft; i++) {
        ret[i] = retLeft[i];
    }
    ret[returnSizeLeft] = root;
    for (i = returnSizeLeft + 1; i < *returnSize; i++) {
        ret[i] = retRight[i - (returnSizeLeft + 1)];
    }
    
    if (retLeft) {
        free(retLeft);
    }
    retLeft = NULL;
    if (retRight) {
        free(retRight);
    }
    retRight = NULL;
    
    return ret;
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator *bSTIterator = NULL;
    int nodeCnt = 0;
    struct TreeNode **res = NULL;

    bSTIterator = (BSTIterator*)malloc(1 * sizeof(BSTIterator));
    bSTIterator->idx = -1;
    bSTIterator->size = -1;
    bSTIterator->treeNodeInorder = NULL;

    res = inorderTraversal(root, &nodeCnt);

    bSTIterator->treeNodeInorder = res;
    bSTIterator->size = nodeCnt;

    return bSTIterator;
}

/* It will always be valid. */
int bSTIteratorNext(BSTIterator* obj) {
    obj->idx += 1;

    return obj->treeNodeInorder[obj->idx]->val;
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    if (obj->size == -1) {
        return false;
    }

    if (obj->idx + 1 < obj->size) {
        return true;
    } else {
        return false;
    }
}

void bSTIteratorFree(BSTIterator* obj) {
    if (obj) {
        free(obj);
        obj = NULL;
    }
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 
 * bool param_2 = bSTIteratorHasNext(obj);
 
 * bSTIteratorFree(obj);
*/
