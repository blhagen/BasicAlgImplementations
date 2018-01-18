/***************************************************************************************
**	Selection Sort: an in-place comparison sort. Selection sort divides the ilst into
**	two parts: the sublist of items already sorted (which is built up from the lef to
**	right at the front/left of the lsit), and the sublist of items remaining to be 
**	sorted taht occupy the rest of the list. Initially, the sorted sublist is empty
**	and the unsorted sublist is the entire input list. The algorithm proceeds by finding
**	the smallest element in the unsorted sublist, exhanging (swapping) it with the 
**	leftmost unsorted element (putting it in sorted order), and moving the sublist
**	boundaries one element to the right.

**	Running time:
**	Selection sort will
**	run in quadratic O(n^2) time, making it inefficient for larg lists. It generally
**	performs worse than insertion sort, but is advantageous in certain situations,
**	particularly when memory is limited.

Pseudocode:
1: function SelectionSort(A, n)
2: 	for i = 1 to n-1 do
3: 		min ← i
4:		for j = i + 1 to j < n do
5: 			if A[j] < A[min] then	
6:       		min ← j
7:			end if
8:		end for
9:		swap A[i], A[min]
10:	end for
11:end function
 
**	Resources: 
**	https://en.wikipedia.org/wiki/Selection_sort
**	https://goo.gl/zUBgLS
***************************************************************************************/

#include <iostream>
using namespace std;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(int arr[], int n) {
	int i, j, min;
	for (i = 0; i < n; i++) {
		min = i;
		for (j = i + 1; j < n; j ++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		swap(arr[i], arr[min]);
	}
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	int arr[] = {5,2,43,6,1,3,2,123,9};
	int n = sizeof(arr)/sizeof(arr[1]);

	cout << "Pre-sorted array: " << endl;
	printArray(arr, n);
	cout << endl << endl;

	selectionSort(arr, n);
	cout << "Array after selectionSort function: " << endl;
	printArray(arr, n);
	cout << endl << endl;

	return 0;
}