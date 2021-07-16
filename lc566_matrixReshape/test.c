#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    // cannot reshape
    if (matSize * (*matColSize) != r * c) {
        *returnSize = matSize;
        *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
        memcpy((*returnColumnSizes), matColSize, sizeof(int) * matSize);
        return mat;
    }

    // reshape
    *returnSize = r;
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    memset(*returnColumnSizes, c, r);
    for (int i = 0; i < matSize; ++i) {
        for (int j = 0; j < matColSize[i]; ++j)
            printf("%d ", *(*(mat) + j)); //*matColSize[i] +j
        printf("\n");
    }
    return mat;
}

int main() {
    int arr[][2] = { {1,2}, {3,4} };
    int matSize = 2;
    int matColSize[] = { 2,2 };
    for (int i = 0; i < matSize; ++i) {
        for (int j = 0; j < matColSize[i]; ++j)
            printf("%d ", *(*(arr) +i*2+ j));
        printf("\n");
    }
    int returnSize;
    int* returnColumnSizes;
    int** arr2 = matrixReshape((int **)&(arr), 2, matColSize, 1, 4, &returnSize, &returnColumnSizes);
    printf("----\n");
    for (int i = 0; i < returnSize; ++i) {
        for (int j = 0; j < matColSize[i]; ++j)
            printf("%d ", *(*(arr2+i)+j));
        printf("\n");
    }
    return 0;
}