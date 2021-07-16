// lc350_intersect.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<stdio.h>

void quickSort(int* arr, int s, int e) {
	if (s >= e) return;
	int left = s, right = e, m = arr[(s + e) / 2], t = 0;
	while (left < right) {
		while (arr[left] < m) left++;
		while (arr[right] > m) right--;
        if (left <= right) {
            t = arr[left];
            arr[left] = arr[right];
            arr[right] = t;
            left++;
            right--;
        }
	}
	quickSort(arr, s, right);
	quickSort(arr, left, e);
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int max_size = (nums1Size > nums2Size) ? nums1Size : nums2Size;
    int* res = (int*)malloc(sizeof(int) * max_size);
    int res_index = 0;

    quickSort(nums1, 0, nums1Size - 1);
    quickSort(nums2, 0, nums2Size - 1);

    int p1 = 0, p2 = 0;
    while (p1 < nums1Size && p2 < nums2Size) {
        if (nums1[p1] == nums2[p2]) {
            // find match!
            res[res_index] = nums1[p1];
            res_index++;
            p1++;
            p2++;
        }
        else if (nums1[p1] < nums2[p2]) {
            p1++;
        }
        else {
            p2++;
        }
    }
    *returnSize = res_index;
    return res;
}

int main()
{
    //[4,7,9,7,6,7]
    //[5, 0, 0, 6, 1, 6, 2, 2, 4]
    int nums1[] = { 4,7,9,7,6,7 };
    int nums2[] = { 5, 0, 0, 6, 1, 6, 2, 2, 4 };
    int res_size = 0;
    int* res = intersect(nums1, sizeof(nums1) / sizeof(int), nums2, sizeof(nums2) / sizeof(int), &res_size);
	
	for (int i = 0; i < res_size; ++i) {
		printf("%d ", res[i]);
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
