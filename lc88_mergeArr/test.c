#include <stdio.h>
#include <stdlib.h>

int* merge_arr(int* arr1, int arr1_size, int* arr2, int arr2_size, int* return_size) {
	int p1 = 0, p2 = 0;
	int* arr = (int*)malloc(sizeof(int) * (arr1_size + arr2_size));
	int index = 0;
	while (p1<arr1_size || p2<arr2_size)
	{
		if (p1 == arr1_size && p2 < arr2_size) {
			arr[index] = arr2[p2];
			index++; p2++;
			continue;
		}
		if (p1 < arr1_size && p2 == arr2_size) {
			arr[index] = arr1[p1];
			index++; p1++;
			continue;
		}
		if (arr1[p1] < arr2[p2]) {
			arr[index] = arr1[p1];
			index++; p1++;
		}
		else if (arr1[p1] > arr2[p2]) {
			arr[index] = arr2[p2];
			index++; p2++;
		}
		else if (arr1[p1] == arr2[p2]) {
			arr[index] = arr2[p2];
			index++; p2++; p1++;
		}
	}
	*return_size = index;
	return arr;
}

int main() {
	int arr1_size, arr2_size;
	scanf_s("%d", &arr1_size);
	scanf_s("%d", &arr2_size);
	int* arr1 = (int*)malloc(sizeof(int) * arr1_size);
	int* arr2 = (int*)malloc(sizeof(int) * arr2_size);
	for (int i = 0; i < arr1_size; ++i) {
		scanf_s("%d", arr1 + i);
	}
	for (int i = 0; i < arr2_size; ++i) {
		scanf_s("%d", arr2 + i);
	}

	for (int i = 0; i < arr1_size; ++i) {
		printf("%d ", arr1[i]);
	}
	printf("\n");
	int return_size;
	int* arr = merge_arr(arr1, arr1_size, arr2, arr2_size, &return_size);
	for (int i = 0; i < return_size; ++i) {
		printf("%d ", arr[i]);
	}
	return 0;
}