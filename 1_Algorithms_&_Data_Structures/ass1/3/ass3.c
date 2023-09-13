#include <stdio.h>
#include <time.h>
#include <string.h>
/* 3rd part of Assignment 1 SD */

// function prototypes
void splitArray(int arr[], int l, int r);
void mergeArray(int arr[], int l, int m, int r);

static void alg1(int *arr, int n) // Bubble sort
{
	int i, j;
    for (i = 0; i < n-1; i++) {        
       for (j = 0; j < n-i-1; j++) {
           if (arr[j] > arr[j+1]){
			  int temp = arr[j];
    		  arr[j] = arr[j+1];
    		  arr[j+1] = temp;
		    }
	   }
	}
}

static void alg2(int *arr, int n) // Selection sort
{
	int i, j, min_i;
    for (i = 0; i < n-1; i++)
    {
        // find the smallest element in unsorted array
        min_i = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_i])
            min_i = j;
 
        // swap the lowest element with the first element
        int temp = arr[min_i];
		arr[min_i] = arr[i];
		arr[i] = temp; 
    }
}

static void alg3(int *arr, int n) // Merge sort
{
	splitArray(arr, 0, n-1); // pass array, array start and array end
}

/* UTILITY FUNCTIONS */
/* Function to split array into sub-arrays of size 1*/
void splitArray(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2; 	// find middle of the array
 
        splitArray(arr, l, m); 		// split first half until size 1
        splitArray(arr, m + 1, r);	// split second half until size 1
 
        mergeArray(arr, l, m, r);
    }
}

/* Function to compare and merge sub arrays */
void mergeArray(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temporary arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // index of first subarray
    j = 0; // index of second subarray
    k = l; // index of merged subarray
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { //add lesser value to array
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of temp arrays */
    for (i; i < n1; i++) {
        arr[k] = L[i];
        k++;
    }
 
    for (j; j < n2; j++) {
        arr[k] = R[j];
        k++;
    }
}

static void read_in_arrays_to_sort(int *arr1, int *arr2, int *arr3, int n1, int n2, int n3)
{
	for(int i=0; i<n1; i++)
	{
		scanf("%d", &arr1[i]);
	}
	for(int i=0; i<n2; i++)
	{
		scanf("%d", &arr2[i]);
	}
	for(int i=0; i<n3; i++)
	{
		scanf("%d", &arr3[i]);
	}

}

static void write_to_file(int *arr1, int *arr2, int *arr3, int n1, int n2, int n3, char *filename)
{
	FILE *f= fopen(filename, "w");
	if(f==NULL)
	{
		printf("Error in creating output file %s", filename);
		return;
	}
	for(int i=0; i<n1; i++)
	{
		fprintf(f, "%d ", arr1[i]);
	};
	fprintf(f, "\n");
	for(int i=0; i<n2; i++)
	{
		fprintf(f, "%d ", arr2[i]);
	}
	fprintf(f, "\n");
	for(int i=0; i<n3; i++)
	{
		fprintf(f, "%d ", arr3[i]);
	}
	fclose(f);

}

static void execute_algorithm(int *arr, int n, void (*sort_alg)())
{
	clock_t t;
	double time_taken;
	t = clock();
	sort_alg(arr,n);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Time needed to sort %d elements was %f seconds\n", n, time_taken);
}

static void copy_input_arrays(int *arr1, int *arr2, int *arr3, int *sarr1, int *sarr2, int *sarr3, int n1, int n2, int n3)
{
	memcpy(arr1, sarr1, n1*sizeof(int));
	memcpy(arr2, sarr2, n2*sizeof(int));
	memcpy(arr3, sarr3, n3*sizeof(int));
}



int main() {
	/* Don't touch main */
  
	const int n1 = 10;
	const int n2 = 1000;
	const int n3 = 10000;
	int arr1[n1];
	int arr2[n2];
	int arr3[n3];
	int sarr1[n1];
	int sarr2[n2];
	int sarr3[n3];

	read_in_arrays_to_sort(sarr1, sarr2, sarr3, n1, n2, n3);
	copy_input_arrays(arr1, arr2, arr3, sarr1, sarr2, sarr3, n1, n2, n3);	

	printf("Execution of the first alg1 algorithm\n");

	execute_algorithm(arr1, n1, alg1);
	execute_algorithm(arr2, n2, alg1);
	execute_algorithm(arr3, n3, alg1);
	write_to_file(arr1, arr2, arr3, n1, n2, n3, "out_alg1");

	copy_input_arrays(arr1, arr2, arr3, sarr1, sarr2, sarr3, n1, n2, n3);	

	printf("Execution of the second alg2 algorithm\n");

	execute_algorithm(arr1, n1, alg2);
	execute_algorithm(arr2, n2, alg2);
	execute_algorithm(arr3, n3, alg2);
	write_to_file(arr1, arr2, arr3, n1, n2, n3, "out_alg2");

	copy_input_arrays(arr1, arr2, arr3, sarr1, sarr2, sarr3, n1, n2, n3);	

	printf("Execution of the third alg3 algorithm\n");

	execute_algorithm(arr1, n1, alg3);
	execute_algorithm(arr2, n2, alg3);
	execute_algorithm(arr3, n3, alg3);
	write_to_file(arr1, arr2, arr3, n1, n2, n3, "out_alg3");
	return 0;
}
