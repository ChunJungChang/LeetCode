/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root){
    int levelSize = 0, nextLevelSize = 0, ret = 0, i = 0;
    struct TreeNode **levelNode = NULL, **copyLevelNode = NULL;
    
    if (!root) {
        return ret;
    }

    levelNode = (struct TreeNode **)malloc(++levelSize * sizeof(struct TreeNode*));
    levelNode[levelSize - 1] = root;
    ret += levelSize;

    while (levelSize) {
        copyLevelNode = (struct TreeNode **)malloc(levelSize * sizeof(struct TreeNode*));
        for (i = 0; i < levelSize; i++) {
            copyLevelNode[i] = levelNode[i];
        }

        if (levelNode) {
            free(levelNode);
            levelNode = NULL;
        }

        levelNode = (struct TreeNode **)malloc(2 * levelSize * sizeof(struct TreeNode*));
        nextLevelSize = 0;
        
        for (i = 0; i < levelSize; i++) {
            if (copyLevelNode[i]->left) {
                levelNode[nextLevelSize] = copyLevelNode[i]->left;
                nextLevelSize++;
            }
            if (copyLevelNode[i]->right) {
                levelNode[nextLevelSize] = copyLevelNode[i]->right;
                nextLevelSize++;
            }
        }
        levelSize = nextLevelSize;
        ret += levelSize;

        if (copyLevelNode) {
            free(copyLevelNode);
            copyLevelNode = NULL;
        }
        
    }

    return ret;
}
