#include <stdio.h>
#include <time.h>
/* 2nd part of Assignment 1 SD */
//function prototype
int get_difference_between_min_and_max_sum_of_k_elems(int arr[], int n, int k);


int main() {
	/* this is code to measure the time of your algorithm, please don't touch it */

    	clock_t t; 
	double time_taken;

    	t = clock(); 
  
	int n;
	scanf("%d", &n);

	int arr[n];
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	int k;
	scanf("%d", &k);

	int outcome=0;
	outcome = get_difference_between_min_and_max_sum_of_k_elems(arr, n, k);


	/* this is the (performance) test code, please don't touch it */

	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("difference between minimum and maximum sum of K elements is %d\n", outcome);
#ifdef TEST_TIME
	printf("time needed was %f seconds\n", time_taken);
#endif
	return 0;
}

int get_difference_between_min_and_max_sum_of_k_elems(int arr[], int n, int k){
    int i, j;
    for (i = 0; i < n-1; i++) { 
		//bubble sort array       
       for (j = 0; j < n-i-1; j++) {
           if (arr[j] > arr[j+1]){
			  int temp = arr[j];
    		  arr[j] = arr[j+1];
    		  arr[j+1] = temp;
		    }
	   }
	}
	
	int min_sum = 0;
	int max_sum = 0;
	for(int m = 0; m < k; m++){
		min_sum += arr[m];			//add lowest k numbers
		max_sum += arr[n-(m+1)];	//add highest k numbers
	}
	//printf("max: %d \n", max_sum);
	//printf("min: %d \n", min_sum);
	
	return(max_sum - min_sum);
}
