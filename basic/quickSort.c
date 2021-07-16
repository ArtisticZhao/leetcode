#include <stdio.h>

// void quickSort(int* nums, int s, int e) {
// 	if (s >= e)
// 		return;
// 	int m = nums[(s+e)/2], lo = s, hi = e, t=0;
// 	while (lo < hi) {
// 		while (nums[lo] < m)
// 			lo++;
// 		while (nums[hi] > m)
// 			hi--;
// 		if(lo<=hi){
// 			t = nums[lo];
// 			nums[lo] = nums[hi];
// 			nums[hi] = t;
// 			hi--;
// 			lo++;
// 		}
// 	}
// 	quickSort(nums, s, hi);
// 	quickSort(nums, lo, e);
// }
void quickSort(int* arr, int s, int e){
    if (s>=e) return;
    int left=s, right=e, mid=arr[(s+e)/2];
    int temp;
    while(left<right){
        while(arr[left]<mid) left++;
        while(arr[right]>mid) right--;
        if(left<=right){
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
    quickSort(arr, s, right);
    quickSort(arr, left, e);
}
int main(int argc, char *argv[])
{
    int arr[] = {5,9,1,4,3,7,6};
    printf("-----------------\n");
    for (int i = 0; i < sizeof(arr)/sizeof(int); ++i) {
        printf("%d ", arr[i]);
    }
    quickSort(arr, 0, sizeof(arr)/sizeof(int)-1);
    printf("-----------------\n");
    for (int i = 0; i < sizeof(arr)/sizeof(int); ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}
