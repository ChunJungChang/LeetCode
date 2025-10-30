/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif

struct hashnode {
    struct TreeNode *key;
    int val;
    UT_hash_handle hh;
};

struct hashnode *hashmap = NULL; 

int rob(struct TreeNode* root){
    int robbery = 0, robberyLeft = 0, robberyRight = 0, notRobbery = 0, ret = 0;
    struct hashnode *node = NULL, *find_node = NULL;
    
    if (!root) {
        return 0;
    }
    
    // Skip child node
    robbery = root->val;
    /*
    if (root->left) {
        robbery += rob(root->left->left) + rob(root->left->right);
    }
    if (root->right) {
        robbery += rob(root->right->left) + rob(root->right->right);
    }
    */
    if (root->left) {
        find_node = NULL;
        HASH_FIND_PTR(hashmap, &root->left->left, find_node);
        if (!find_node) {
            robbery += rob(root->left->left);
        } else {
            robbery += find_node->val;
        }

        find_node = NULL;
        HASH_FIND_PTR(hashmap, &root->left->right, find_node);
        if (!find_node) {
            robbery += rob(root->left->right);
        } else {
            robbery += find_node->val;
        }
    }
    if (root->right) {
        find_node = NULL;
        HASH_FIND_PTR(hashmap, &root->right->left, find_node);
        if (!find_node) {
            robbery += rob(root->right->left);
        } else {
            robbery += find_node->val;
        }

        find_node = NULL;
        HASH_FIND_PTR(hashmap, &root->right->right, find_node);
        if (!find_node) {
            robbery += rob(root->right->right);
        } else {
            robbery += find_node->val;
        }   
    }

    // Consider child node
    /*
    notRobbery = rob(root->left) + rob(root->right);
    */
    find_node = NULL;
    HASH_FIND_PTR(hashmap, &root->left, find_node);
    if (!find_node) {
        notRobbery += rob(root->left);
    } else {
        notRobbery += find_node->val;
    }
    find_node = NULL;
    HASH_FIND_PTR(hashmap, &root->right, find_node);
    if (!find_node) {
        notRobbery += rob(root->right);
    } else {
        notRobbery += find_node->val;
    }
        
    ret = max(robbery, notRobbery);

    node = (struct hashnode *)malloc(sizeof(struct hashnode));
    node->key = root;
    node->val = ret;
    HASH_ADD_PTR(hashmap, key, node);

    return ret;
}
