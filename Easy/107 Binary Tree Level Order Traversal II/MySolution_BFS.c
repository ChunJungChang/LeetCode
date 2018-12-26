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
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int maxDepth(struct TreeNode* root)
{
    int leftDepth = 0;
    int rightDepth = 0;
    int depth = 0;
    
    if (!root) {
        return depth;
    }
    
    leftDepth = 1 + maxDepth(root->left);
    rightDepth = 1 + maxDepth(root->right);
    
    if (leftDepth >= rightDepth) {
        depth = leftDepth;
    } else {
        depth = rightDepth;
    }
    
    return depth;
}

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int treeDepth = 0;
    int **res = NULL;
    int level_size = 0;
    struct TreeNode **level_node = NULL;
    int idx = 0;
    
    if (!root) {
        *columnSizes = NULL;
		*returnSize = 0;

        return res;
    }
    
    treeDepth = maxDepth(root);
    *columnSizes = (int*)malloc(treeDepth * sizeof(int));
    res = (int**)malloc(treeDepth * sizeof(int*));
    idx = treeDepth - 1;

    level_node = (struct TreeNode**)malloc((++level_size) * sizeof(struct TreeNode*));
    level_node[0] = root;
    
    while (level_size != 0) {
        int node_cnt = level_size;
        level_size = 0;
        
        /**
         * Same as (*columnSizes)[idx] = node_cnt;
         */
        *((*columnSizes) + idx) = node_cnt;
        res[idx] = (int*)malloc(node_cnt * sizeof(int*));
        
        struct TreeNode **node = (struct TreeNode**)malloc((node_cnt) * sizeof(struct TreeNode*));
        for (int i = 0 ; i < node_cnt ; i++) {
            node[i] = level_node[i];
            level_node[i] = NULL;
        }
        free(level_node);
        
        level_node = (struct TreeNode**)malloc(2 * node_cnt * sizeof(struct TreeNode*));
        for (int i = 0 ; i < node_cnt ; i++) {
            struct TreeNode *ptr = node[i];
            node[i] = NULL;
        
            res[idx][i] = ptr->val;
            
            if (ptr->left) {
                level_node[level_size++] = ptr->left;
            }
            if (ptr->right) {
                level_node[level_size++] = ptr->right;
            }
        }
        --idx;
        free(node);
    }
    free(level_node);
    
    *returnSize = treeDepth;

    return res;
}
