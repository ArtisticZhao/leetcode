#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes){
    if(matSize*matColSize[0] != r*c) {
        *returnSize = matSize;
        *returnColumnSizes = matColSize;
        return mat;
    }
    // for(int i=0; i<matSize; ++i){
    //     for(int j=0; j<matColSize[i]; ++j){
    //         // printf("%d, %d: %d \n", i,j,*(*(mat+i)+j));
    //         printf("%d ", mat[i][j]);
    //     }
    // }
    int** res = (int**)malloc(sizeof(int*)*r);
    *returnSize = r;
    *returnColumnSizes = (int*)malloc(sizeof(int)*r);
    for(int i=0; i<r; ++i){
        res[i] = (int*)malloc(sizeof(int)*c);
        *(*returnColumnSizes+i)= c;
        for(int j=0; j<c; ++j){
            int t = i*c+j;
            res[i][j] = mat[t/matColSize[0]][t%matColSize[0]];
        }
    }
    printf("%d*%d",*returnSize, *(*returnColumnSizes));
    return res;
}

int main() {
    int arr[][2] = { {1,2}, {3,4} };
    int matSize = 2;
    int matColSize[] = { 2,2 };
    int** arr_in = (int**)malloc(sizeof(int*)*2);
    for (int i = 0; i < matSize; ++i) {
        arr_in[i] = (int*)malloc(sizeof(int)*matColSize[i]);
        for(int j=0; j<matColSize[i]; ++j){
            arr_in[i][j] = arr[i][j];
        }
    }

    int returnSize;
    int* returnColumnSizes;
    int** arr2 = matrixReshape(arr_in, 2, matColSize, 1, 4, &returnSize, &returnColumnSizes);
    printf("----\n");
    for (int i = 0; i < returnSize; ++i) {
        for (int j = 0; j < returnColumnSizes[i]; ++j)
            printf("%d ", *(*(arr2+i)+j));
        printf("\n");
    }
    return 0;
}
