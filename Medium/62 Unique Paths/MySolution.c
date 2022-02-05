

int uniquePaths(int m, int n){
    int pathArr[101][101] = {0}, i = 0, j = 0;
    
    for (i = 0; i < m; i++) {
        pathArr[i][0] = 1;
    }
    for (j = 0; j < n; j++) {
        pathArr[0][j] = 1;
    }
    
    for (i = 1; i < m; i++) {
        for (j = 1; j < n; j++) {
            pathArr[i][j] = pathArr[i - 1][j] + pathArr[i][j - 1];
        }
    }
    
    return pathArr[m - 1][n - 1];
}
