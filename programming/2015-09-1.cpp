
#include <iostream>

using namespace std;

bool member(int x, int a[], int size) {

	if (size == 0) return false;
	
	return a[size / 2] == x || (a[size / 2] < x && member(x, a, size / 2)) || (a[size / 2] > x && member(x, a + size / 2, size));

}

void printArr(int* nums, int n) {
	for (int i = 0; i < n; i++) {
		cout << nums[i] << " ";
	}
	cout << "\n";
}

void selectionSort(int* nums, int n) {
	for (int i = 0; i < n; i++) {
		int min = i;
		
		for (int j = i + 1; j < n; j++) {
			if (nums[j] < nums[min]) min = j;		
		}

		if (min != i) {
			int x = nums[i];
			nums[i] = nums[min];
			nums[min] = x;
		}
	}

}

//int main() { 
//
//	int arr[] = { 4, 3, 6, -1, 0, 11, 10 };
//
//	selectionSort(arr, 7);
//	printArr(arr, 7);
//
//	return 0;
//}

