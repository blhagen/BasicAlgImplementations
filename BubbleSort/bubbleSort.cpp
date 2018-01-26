/***************************************************************************************
**	Bubble Sort: an in-place comparison sort. For the length of the list, bubble sort 
**	compares two adjacent elements, swapping them if they are not in order. The process 
**	is then repeated until no more swapping is needed. The first iteration requiring no
**	swaps is the last iteration and indicates that the list is sorted.
**	Main advantages of Bubble Sort is that it is 1) simple and 2) doesn't require extra
**	storage space (operates in-place)

**	Complexity/Running time:
**	Bubble sort is not considered optimal, as it requires multiple iterations over the
**	array.
**	The worst and average case is O(n^2) time, making it inefficient for large lists. 
**	It generally performs worse than other O(n^2) sorting algorithms (such as insertion  
**	sort, but is advantageous in certain situations, particularly when a list is known 
**	to be 'mostly sorted', but may occasionally have some out-of-order elements nearly 
**	in position.

Pseudocode:
1: function BubbleSort(A, n)
2: 	for i = 0 to n-1 do
3:		for j = 0 to j < n - i - 1 do
4: 			if A[j] > A[j+1] then	
5:       		swap A[j], A[j+1]
6:			end if
7:	end for
8:end function
 
**	If I don't use the bool swapped variable, does it impact the speed??

**	Resources: 
**	https://en.wikipedia.org/wiki/Bubble_sort
**	SoloLearn app
**	https://www.geeksforgeeks.org/bubble-sort/
***************************************************************************************/

#include <iostream>
using namespace std;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int arr[], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < (n - i - 1); j ++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
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

	bubbleSort(arr, n);
	cout << "Array after bubbleSort function: " << endl;
	printArray(arr, n);
	cout << endl << endl;

	return 0;
}