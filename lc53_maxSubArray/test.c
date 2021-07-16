#include <stdio.h>
#include <limits.h>
int maxSubArray(int* nums, int numsSize){
    int max = INT_MIN;

    for(int i=0; i<numsSize; ++i){
        int temp = nums[i];
        if(max<temp) max=temp;
        for(int j=i+1; j<numsSize; ++j){
            temp += nums[j];
            if(max<temp) max=temp;
        }
    }
    return max;
}

int main(int argc, char const *argv[])
{
    /* code */
    int arr[] = {1};
    int res = maxSubArray(arr, sizeof(arr)/sizeof(int));
    printf("%d\n", res);
    return 0;
}
