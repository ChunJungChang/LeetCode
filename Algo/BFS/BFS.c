void BFS(struct TreeNode* root) {
    int level_size = 0;
    struct TreeNode **level_node = NULL;
    
    if (!root) {
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
        if (level_node) {
            free(level_node);
            level_node = NULL;
        }
        
        /* Lazy to count how many nodes are in next level, just allocate maximum size */
        level_node = (struct TreeNode**)malloc(2 * node_cnt * sizeof(struct TreeNode*));
        for (int i = 0 ; i < node_cnt ; i++) {
            struct TreeNode *ptr = node[i];
            node[i] = NULL;
            
             /* Use ptr to do something */
            
            if (ptr->left) {
                level_node[level_size++] = ptr->left;
            }
            if (ptr->right) {
                level_node[level_size++] = ptr->right;
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
}
