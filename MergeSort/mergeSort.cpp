/***************************************************************************************
**	Merge Sort is dividing the array in half over and over again until each subarray is 
**	consists of a single element. Then, those items are merged in sorted order.

**	Divide: Divided unsorted, n-element sequence into two subsequences of n/2 elements.
**	Conquer: Sort the two subsequences recursively using mergeSort().
**	Combine: Merge the two sorted subsequences to produce the sorted answer.

**	Running time:
**	Theta(1) only if n = 1;
**	Else, 2T(n/2) + O(n) if n > 1
**	== O(n lg n)

**	Merge Sort asymptotically beats insertion sort. Note that, with merge sort, we don't
**	know if the list is already sorted until the end of the process, so insertion sort
**	can be better for 'nearly sorted' lists.

Pseudocode:
mergeSort(A[1 ... n])
1: If n = 1, done
2: Recursively sort A[1 ... [n/2]]	
3: Recursively sort A[[n/2]+1 ... n]
4: Merge(A, 0, n, [n/2])
5: end function
 
**	Resources: 
**	SoloLearm app
**	CS325 notes
***************************************************************************************/

#include <iostream>
using namespace std;

// we will need a merge function to merge two subarrays into one sorted array
void merge(int *a, int from, int to, int mid) {
	int i = from;
	int j = mid + 1;
	int k = 0;

	int temp[to - from + 1];

	//merge the two parts into array temp[]
	while (i <= mid && j <= to) {
		if (a[i] < a[j]) {
			temp[k] = a[i];
			k++;
			i++;
		}
		else {
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	//insert all the remaining vlaues from i to mid into array temp[]
	while (i <= mid) {
		temp[k] = a[i];
		k++;
		i++;
	}

	//insert all remaining values from j to 'to' into array temp[]
	while (j <= to) {
		temp[k] = a[j];
		k++;
		j++;
	}

	//assign sorted data stored in temp[] to a[]
	for (i = from; i <= to; i ++) {
		a[i] = temp[i - from];
	}
}

// 'from' -> 0, ie, the starting point element position
// 'to' -> n, ie, number of elements in sequence
void mergeSort(int *a, int from, int to) {
	int mid;
	if (from < to) {
		mid = (from + to) / 2;

		mergeSort(a, from, mid);
		mergeSort(a, mid + 1, to);
		merge(a, from, to, mid);
	}
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	int arr[] = {5,2,43,6,1,3,2,123,2};
	int n = sizeof(arr)/sizeof(arr[1]);

	cout << "Pre-sorted array: " << endl;
	printArray(arr, n);
	cout << endl << endl;

	mergeSort(arr, 0, n);
	cout << "Array after selectionSort function: " << endl;
	printArray(arr, n);
	cout << endl << endl;

	return 0;
}