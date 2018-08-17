#define MAX_LEVEL_SIZE 100

void BFS(struct TreeNode* root) {
    int level_size = 0;
    struct TreeNode *level_node[MAX_LEVEL_SIZE] = {0};
    
    if (!root) {
        return NULL;
    }
    
    level_node[0] = root;
    level_size++;
    
    while (level_size) {
        int node_cnt = level_size;
        level_size = 0;
        struct TreeNode *node[MAX_LEVEL_SIZE] = {0};
        memcpy(node, level_node, MAX_LEVEL_SIZE);
        
        struct TreeNode *ptr = NULL;
        
        for (int i = 0 ; i < node_cnt ; i++) {
            ptr = node[i];
            node[i] = NULL;
            /* Do something */
           
            if (ptr->left) {
                level_node[level_size++] = ptr->left;
            }
            if (ptr->right) {
                level_node[level_size++] = ptr->right;
            }
            ptr = NULL;
        }
    }
}
