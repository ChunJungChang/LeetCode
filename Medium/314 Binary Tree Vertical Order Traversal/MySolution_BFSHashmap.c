/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/**
 * Note, The key in hashmap shall be unique.
 * However, in this solution, the keys are not unique. 
 */

struct hashOrderNode_t {
    int key;
    struct TreeNode *val;
    UT_hash_handle hh;
};
struct hashTreeNode_t {
    struct TreeNode *key;
    int val;
    UT_hash_handle hh;
};

struct hashOrderNode_t *hashOrderMap = NULL; /* The order is horizontal and vertical  */
struct hashTreeNode_t *hashTreeMap = NULL; /* Record vertical of node for child */

int** verticalOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    int level_size = 0;
    struct TreeNode **level_node = NULL;
    struct hashOrderNode_t *hashOrderNode = NULL, *hashOrderNodeTmp = NULL;
    struct hashTreeNode_t *hashTreeNode = NULL, *hashTreeNodeTmp = NULL;
    
    if (!root) {
        return NULL;
    }
    
    level_node = (struct TreeNode**)malloc((++level_size) * sizeof(struct TreeNode*));
    level_node[0] = root;
    hashOrderNode = (struct hashOrderNode_t *)malloc(sizeof(struct hashOrderNode_t));
    hashOrderNode->key = 0;
    hashOrderNode->val = root;
    HASH_ADD_INT(hashOrderMap, key, hashOrderNode);
    hashTreeNode = (struct hashTreeNode_t *)malloc(sizeof(struct hashTreeNode_t));
    hashTreeNode->key = root;
    hashTreeNode->val = 0;
    HASH_ADD_PTR(hashTreeMap, key, hashTreeNode);
    
    /**
     * BFS, the nodes in hashmap are horizontal order
     */
    while (level_size != 0) {
        int node_cnt = level_size;
        level_size = 0;
        int verticalVal = 0;
        
        struct TreeNode **node = (struct TreeNode**)malloc(node_cnt * sizeof(struct TreeNode*));
        /* Copy the nodes in current level */
        for (int i = 0 ; i < node_cnt ; i++) {
            node[i] = level_node[i];
            level_node[i] = NULL;
        }
        if (level_node) {
            free(level_node);
            level_node = NULL;
        }
        
        /* Lazy to count how many nodes are in next level, just allocate maximum size */
        level_node = (struct TreeNode**)malloc(2 * node_cnt * sizeof(struct TreeNode*));
        for (int i = 0 ; i < node_cnt ; i++) {
            struct TreeNode *ptr = node[i];
            node[i] = NULL;
            
            /* Find vertical index of ptr for child */
            HASH_FIND_PTR(hashTreeMap, &ptr, hashTreeNode);
            if (hashTreeNode) {
                verticalVal = hashTreeNode->val;
            }
            
            if (ptr->left) {
                level_node[level_size++] = ptr->left;

                hashOrderNode = (struct hashOrderNode_t *)malloc(sizeof(struct hashOrderNode_t));
                hashOrderNode->key = verticalVal - 1;
                hashOrderNode->val = ptr->left;
                HASH_ADD_INT(hashOrderMap, key, hashOrderNode);
                hashTreeNode = (struct hashTreeNode_t *)malloc(sizeof(struct hashTreeNode_t));
                hashTreeNode->key = ptr->left;
                hashTreeNode->val = verticalVal - 1;
                HASH_ADD_PTR(hashTreeMap, key, hashTreeNode);
            }
            if (ptr->right) {
                level_node[level_size++] = ptr->right;

                hashOrderNode = (struct hashOrderNode_t *)malloc(sizeof(struct hashOrderNode_t));
                hashOrderNode->key = verticalVal + 1;
                hashOrderNode->val = ptr->right;
                HASH_ADD_INT(hashOrderMap, key, hashOrderNode);
                hashTreeNode = (struct hashTreeNode_t *)malloc(sizeof(struct hashTreeNode_t));
                hashTreeNode->key = ptr->right;
                hashTreeNode->val = verticalVal + 1;
                HASH_ADD_PTR(hashTreeMap, key, hashTreeNode);
            }
        }

        if (node) {
            free(node);
            node = NULL;
        }
    }

    if (level_node) {
        free(level_node);
        level_node = NULL;
    }

    int *calcElem = NULL;
    calcElem = (int*)calloc(201, sizeof(int));
    int **arr = NULL;
    arr = (int**)calloc(201, sizeof(int*));
    int idx = 0, size = 0, i = 0, j = 0, k = 0;
    int **ret = NULL;
    /**
      * Index: -100~-1      0(root)     1~100
      * Shift:    0~99    100(root)   101~200
      *
      * Copy elements from hash table to array
      */
    HASH_ITER(hh, hashOrderMap,hashOrderNode, hashOrderNodeTmp) {
        idx = hashOrderNode->key;
        idx += 100;

        calcElem[idx] += 1;
        size = calcElem[idx];

        if (!arr[idx]) {
            arr[idx] = (int*)calloc(1, sizeof(int));
        } else {
            arr[idx] = (int*)realloc(arr[idx], size * sizeof(int));
        }

        arr[idx][size - 1] = hashOrderNode->val->val;
    }
    /**
     * Caculate return size
     */
    for (i = 0; i < 201; i++) {
        if (calcElem[i] > 0) {
            *returnSize += 1;
        }
    }
    /**
     * Copy elements from array to ret
     */
    returnColumnSizes[0] = (int *)malloc(*returnSize * sizeof(int));
    ret = (int**)calloc(*returnSize, sizeof(int*));
    j = 0;
    for (i = 0; i < 201; i++) {
        if (calcElem[i] > 0) {
            returnColumnSizes[0][j] = calcElem[i];

            ret[j] = (int*)calloc(calcElem[i], sizeof(int));
            for (k = 0; k < calcElem[i]; k++) {
                ret[j][k] = arr[i][k];
            }

            j++;
        }
    }

    HASH_ITER(hh, hashOrderMap, hashOrderNode, hashOrderNodeTmp) {
        HASH_DEL(hashOrderMap, hashOrderNode);
        free(hashOrderNode);
    }
    HASH_ITER(hh, hashTreeMap, hashTreeNode, hashTreeNodeTmp) {
        HASH_DEL(hashTreeMap, hashTreeNode);
        free(hashTreeNode);
    }

    return ret;
}
