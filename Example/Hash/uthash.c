struct hashnode {
    struct TreeNode *key;
    int val;
    UT_hash_handle hh;
};

struct hashnode *hashmap = NULL;

int rob(struct TreeNode* root) {
    struct hashnode *node = NULL, *find_node = NULL, *cur = NULL, *tmp = NULL;

    // Add
    node = (struct hashnode *)malloc(sizeof(struct hashnode));
    node->key = root;
    node->val = root->val;
    HASH_ADD_PTR(hashmap, key, node);

    // Find
    HASH_FIND_PTR(hashmap, &root, find_node);
    if (!find_node) {
        printf("Not find the node\n");
    } else {
        printf("Find the node: %d\n", find_node->val);
    }

    // Iterate
    HASH_ITER(hh, hashmap, cur, tmp) {
        printf("cur: %d\n", cur->val);
    }

    return 0;
}
