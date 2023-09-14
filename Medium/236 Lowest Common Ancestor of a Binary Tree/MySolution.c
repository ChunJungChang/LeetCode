/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int pIdx = 0;
int qIdx = 0;

struct TreeNode *pPath[100000];
struct TreeNode *qPath[100000];

bool lowestCommonAncestorHelper(struct TreeNode* root, struct TreeNode* target, struct TreeNode **path, int *idx) {
    bool ret = false;

    if (!root) {
        return false;
    }

    if (root == target) {
        path[*idx] = root;
        (*idx)++;
        return true;
    } else {
        ret = lowestCommonAncestorHelper(root->left, target, path, idx) |
              lowestCommonAncestorHelper(root->right, target, path, idx);
    }

    if (ret) {
        path[*idx] = root;
        (*idx)++;
    }

    return ret;
}


struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    bool pRet = false, qRet = false;
    struct TreeNode *ret = NULL;
    int i = 0, j = 0;

    pIdx = 0;
    pRet = lowestCommonAncestorHelper(root, p, &pPath, &pIdx);
    /*
    printf("pIdx: %d\n", pIdx);
    for (i = 0; i < pIdx; i++) {
        printf("%d ", pPath[i]->val);
    }
    printf("\n");
    */

    qIdx = 0;
    qRet = lowestCommonAncestorHelper(root, q, &qPath, &qIdx);
    /*
    printf("qIdx: %d\n", qIdx);
    for (i = 0; i < qIdx; i++) {
        printf("%d ", qPath[i]->val);
    }
    printf("\n");
    */

    i = pIdx - 1;
    j = qIdx - 1;
    while (i >= 0 && j >= 0) {
        if (pPath[i] == qPath[j]) {
            /*
            printf("i: %d, j: %d, root->val: %d\n", i, j, pPath[i]->val);
            */
            ret = pPath[i];
        }
        i--;
        j--;
    }

    pIdx = 0;
    qIdx = 0;

    return ret;
}
