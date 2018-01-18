/***************************************************************************************
**	Insertion Sort: a simple sorting algorithm that works the way we sort playing cards
**	in our hands. We sort the first two cards and then place the third card in the 
**	appropriate position within the first two, and then the 4th card is positioned 
**	within the first three, and so on until the whole hand is sorted.
**  During an interation, an element of the list is inserted into the sorted portion of
**	the array to its left. So, for each iteration, we have an array of sorted elements 
**	to the left, and an array of elements to be sorted to the right.

**	Running time:
**	Best case is if the array is already sorted. Then, insertion sort will run in O(n).
**	Worst case is if the array is sorted in reverse order, Then, insertion sort will
**	run in quadratic O(n^2) time. This running time is the same for average case.

Pseudocode:

i ← 1
while i < length(A)
    j ← i
    while j > 0 and A[j-1] > A[j]
        swap A[j] and A[j-1]
        j ← j - 1
    end while
    i ← i + 1
end while
***************************************************************************************/

#include <iostream>
using namespace std;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insertionSort(int arr[], int n) {
	int i, j;
	for (i = 1; i < n; i++) {
		j = i;
		while (j > 0 && arr[j-1] > arr[j]) {
			swap(arr[j], arr[j-1]);
			j--;
		}
	}
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	int arr[] = {5,2,43,6,1,3,2};
	int n = sizeof(arr)/sizeof(arr[1]);

	cout << "Pre-sorted array: " << endl;
	printArray(arr, n);
	cout << endl << endl;

	insertionSort(arr, n);
	cout << "Array after insertionSort function: " << endl;
	printArray(arr, n);
	cout << endl << endl;

	return 0;
}