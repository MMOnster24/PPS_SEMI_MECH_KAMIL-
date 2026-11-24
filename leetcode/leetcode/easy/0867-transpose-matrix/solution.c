int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int m = matrixSize;
    int n = matrixColSize[0];
    
    // Allocate result matrix with swapped dimensions (n x m)
    int** ans = (int**)malloc(n * sizeof(int*));
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        ans[i] = (int*)malloc(m * sizeof(int));
        (*returnColumnSizes)[i] = m;
    }
    
    // Fill transposed matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ans[j][i] = matrix[i][j];
        }
    }
    
    *returnSize = n;
    return ans;
}