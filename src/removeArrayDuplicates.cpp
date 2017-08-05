/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

void sortingArray(int *Arr, int len){
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (Arr[i] > Arr[j]) {
				int temp = Arr[i];
				Arr[i] = Arr[j];
				Arr[j] = temp;
			}
		}
	}
}

void removeIndices(int *Arr, int *len, int p)
{
	int i;
	for (i = p; i<*len - 1; i++)
		Arr[i] = Arr[i + 1];
	*len -= 1;
}


int removeArrayDuplicates(int *Arr, int len)
{
	
	if (Arr == NULL || len < 0)
		return -1;
	else {
		sortingArray(Arr, len);
		for (int i = 0; i < len - 1; i++){
			for (int j = i + 1; j < len;){
				if (Arr[i] == Arr[j])
					removeIndices(Arr, &len, j);
				else
					j++;
			}
		}
		return len;
	}
}
