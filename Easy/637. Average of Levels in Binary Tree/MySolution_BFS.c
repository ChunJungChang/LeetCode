/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    int dep = 0, level_size = 0;
    struct TreeNode **level_node = NULL;
    double *ret = NULL;
    
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    
    level_node = (struct TreeNode**)malloc((++level_size) * sizeof(struct TreeNode*));
    level_node[0] = root;
    
    while (level_size != 0) {
        int node_cnt = level_size;
        level_size = 0;
        
        struct TreeNode **node = (struct TreeNode**)malloc(node_cnt * sizeof(struct TreeNode*));
        /* Copy the nodes in current level */
        for (int i = 0 ; i < node_cnt ; i++) {
            node[i] = level_node[i];
            level_node[i] = NULL;
        }
        free(level_node);
        
        /* Lazy to count how many nodes in next level, just allocate maximum size */
        level_node = (struct TreeNode**)malloc(2 * node_cnt * sizeof(struct TreeNode*));
        double sum = 0;
        for (int i = 0 ; i < node_cnt ; i++) {
            struct TreeNode *ptr = node[i];
            node[i] = NULL;
            
            sum += ptr->val;
            
            if (ptr->left) {
                level_node[level_size++] = ptr->left;
            }
            if (ptr->right) {
                level_node[level_size++] = ptr->right;
            }
        }
        free(node);
        
        ret = (double*)realloc(ret, (dep + 1) * sizeof(double));
        ret[dep++] = sum / node_cnt;
    }
    free(level_node);
    
    *returnSize = dep;
    return ret;
}
