/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int path_record[100] = {[0 ... 99] = -101};

void reverse(char s[])
{
    int i, j;
    char c;
 
    for (i = 0, j = strlen(s) -1 ; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[])
{
    int i, sign;
 
    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */

    i = 0;
    do {       /* generate digits in reverse order */
        s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */
    
    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';

    reverse(s);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    char itoa_tmp[5], *path = NULL;
    char **res_left = NULL, **res_right = NULL, **ret = NULL;
    int returnSize_left = 0, returnSize_right = 0, size = 0, depth = 0, path_len = 0, i = 0;
    
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    
    for (i = 0; i < 100; i++) {
        if (path_record[i] == -101) {
            path_record[i] = root->val;
            
            depth = i + 1;
            
            break;
        }
    }

    if (root->left) {
        res_left = binaryTreePaths(root->left, &returnSize_left);
    }
    size += returnSize_left;

    if (root->right) {
        res_right = binaryTreePaths(root->right, &returnSize_right);
    }
    size += returnSize_right;

    if (!(root->left) && !(root->right)) {
        size = 1;
        ret = (char**)calloc(size, sizeof(char *));
        
        //      strlen("-100") + ->                + \n
        path_len = (depth * 4) + ((depth - 1) * 2) + 1;
        ret[size - 1] = (char *)calloc(path_len, sizeof(char));
        for (i = 0; i < depth; i++) {
            itoa(path_record[i], itoa_tmp);
            strcat(ret[size - 1], itoa_tmp);

            if (i != depth - 1) {
                strcat(ret[size - 1], "->");
            }
        }

        /* Debug */
        /*
        printf("Find path: %s\n", ret[0]);
        */
    } else {
        ret = (char**)calloc(size, sizeof(char *));
        
        for (i = 0; i < returnSize_left; i++) {
            ret[i] = (char*)calloc(strlen(res_left[i]) + 1, sizeof(char));
            snprintf(ret[i], strlen(res_left[i]) + 1, "%s", res_left[i]);
            free(res_left[i]);
        }
        if (res_left)
            free(res_left);

        for (i = 0; i < returnSize_right; i++) {
            ret[returnSize_left + i] = (char*)calloc(strlen(res_right[i]) + 1, sizeof(char));
            snprintf(ret[returnSize_left + i], strlen(res_right[i]) + 1, "%s", res_right[i]);
            free(res_right[i]);
        }
        if (res_right)
            free(res_right);

        /* Debug */
        /*
        for (i = 0; i < size; i++) {
            printf("ret[%d]: %s\n", i, ret[i]);
        }
        */
    }
    
    path_record[depth - 1] = -101;

    *returnSize = size;
    return ret;
}
