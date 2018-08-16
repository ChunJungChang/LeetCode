/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** A, int ARowSize, int *AColSizes, int** columnSizes, int* returnSize) {
    int i = 0, j = 0;
    int **res = NULL;
    
    /*
     * ARowSize is a local variable
     * Thus, *returnSize = ARowSize;
     * can not be repleaced to
     * returnSize = &ARowSize;
     */
    *returnSize = ARowSize;
    /*
     * int** columnSizes have already point to a pointer
     * i.e. int *ptr; flipAndInvertImage(X, X, X, &ptr, X);
     * Thus, *columnSizes = (int*)malloc(ARowSize * sizeof(int));
     * can not be repleaced to 
     * int *tmp = (int*)malloc(ARowSize * sizeof(int)); columnSizes = &tmp;
     */
    *columnSizes = (int*)malloc(ARowSize * sizeof(int));
    res = (int**)malloc(ARowSize * sizeof(int*));
    
    for (i = 0 ; i < ARowSize ; i++) {
        *((*columnSizes) + i) = AColSizes[i]; // same as (*columnSizes)[i] = AColSizes[i];
        res[i] = (int*)malloc((*columnSizes)[i] * sizeof(int));
  
        int k = (*columnSizes)[i] - 1;
        for (j = 0 ; j < (*columnSizes)[i] ; j++, k--) {
            res[i][k] = !A[i][j];
        }
    }
    
    return res;
}
