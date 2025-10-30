/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct hashnode {
    struct TreeNode *key;
    int leftMin;
    int rightMax;
    UT_hash_handle hh;
};

struct hashnode *hashmap = NULL;

bool isValidBST(struct TreeNode* root){
    struct hashnode *node = NULL, *findNodeLeft = NULL, *findNodeRight = NULL;
    int leftMin = INT_MAX, leftMax = INT_MIN, rightMin = INT_MAX, rightMax = INT_MIN;
    bool ret = true;

    if (!root) {
        return true;
    }
    if (!root->left && !root->right) {
        node = (struct hashnode *)malloc(sizeof(struct hashnode));
        node->key = root;
        node->leftMin = root->val;
        node->rightMax = root->val;
        HASH_ADD_PTR(hashmap, key, node);

        return true;
    }

    ret = isValidBST(root->left) & isValidBST(root->right);

    HASH_FIND_PTR(hashmap, &root->left, findNodeLeft);
    if (findNodeLeft) {
        leftMin = findNodeLeft->leftMin;
        leftMax = findNodeLeft->rightMax;
        if (leftMin < root->val && leftMax < root->val) {
            ret &= true;
        } else {
            ret &= false;
        }
    }

    HASH_FIND_PTR(hashmap, &root->right, findNodeRight);
    if (findNodeRight) {
        rightMin = findNodeRight->leftMin;
        rightMax = findNodeRight->rightMax;
        if (root->val < rightMin && root->val < rightMax) {
            ret &= true;
        } else {
            ret &= false;
        }
    }

    if (root->left) {
        if (root->left->val < root->val) {
            ret &= true;
        } else {
            ret &= false;
        }
        if (root->left->val < leftMin) {
            leftMin = root->left->val;
        }
        if (leftMax < root->left->val) {
            leftMax = root->left->val;
        }
    }
    if (root->right) {
        if (root->val < root->right->val) {
            ret &= true;
        } else {
            ret &= false;
        }
        if (root->right->val < rightMin) {
            rightMin = root->right->val;
        }
        if (rightMax < root->right->val) {
            rightMax = root->right->val;
        }
    } 
    if (!root->left) {
        leftMin = rightMin;
        leftMax = rightMin;
    }
    if (!root->right) {
        rightMin = leftMax;
        rightMax = leftMax;
    }

    node = (struct hashnode *)malloc(sizeof(struct hashnode));
    node->key = root;
    node->leftMin = leftMin;
    node->rightMax = rightMax;
    HASH_ADD_PTR(hashmap, key, node);

    return ret;
}
