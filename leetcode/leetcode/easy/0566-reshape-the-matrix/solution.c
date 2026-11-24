/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    int originalRows = matSize;
    int originalCols = matColSize[0];
    
    // If reshape is not possible, return original matrix
    if (originalRows * originalCols != r * c) {
        *returnSize = originalRows;
        *returnColumnSizes = matColSize; // Reuse existing column sizes
        return mat;
    }
    
    // Allocate new matrix
    *returnSize = r;
    *returnColumnSizes = malloc(sizeof(int) * r);
    int** ans = malloc(sizeof(int*) * r);
    
    for (int i = 0; i < r; i++) {
        (*returnColumnSizes)[i] = c;
        ans[i] = malloc(sizeof(int) * c);
    }
    
    // Copy elements using linear indexing
    for (int i = 0; i < r * c; i++) {
        ans[i / c][i % c] = mat[i / originalCols][i % originalCols];
    }
    
    return ans;
}   