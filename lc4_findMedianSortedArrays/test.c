#include <stdbool.h>
#include <stdio.h>

int find_index_in_2_arrays(int* nums1, int nums1Size, int* nums2, int nums2Size, int index){
    if(index < nums1Size){
        return nums1[index];
    }else{
        return nums2[index-nums1Size];
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    //
    bool is_calc = !((nums1Size+nums2Size)%2);
    int median_index = 0;
    if(is_calc){
        //
        median_index = (nums1Size+nums2Size)/2-1;
        return ((double)find_index_in_2_arrays(nums1, nums1Size, nums2, nums2Size, median_index) +
               (double)find_index_in_2_arrays(nums1, nums1Size, nums2, nums2Size, median_index+1))/2;
    }else{
        median_index = (nums1Size+nums2Size)/2;
        return (double)find_index_in_2_arrays(nums1, nums1Size, nums2, nums2Size, median_index);
    }
}

int main(int argc, char const *argv[])
{
    int a1[] = {1, 2};
    int a2[] = {3, 4};
    double res = findMedianSortedArrays(a1, sizeof(a1)/sizeof(int), a2, sizeof(a2)/sizeof(int));
    printf("%f", res);
    return 0;
}
