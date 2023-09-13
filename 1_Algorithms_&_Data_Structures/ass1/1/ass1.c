#include <stdio.h>
#include <time.h>
/* 1st part of Assignment 1 SD */
//function prototype
int get_minimum_number_with_k_occurences(int arr[], int n, int k);

int main() {
	/* this is code to measure the time of your algorithm, please don't touch it */

    	clock_t t; 
	double time_taken;

    	t = clock(); 
  
	int n;
	scanf("%d", &n);

	int arr[n];
	for(int i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}

	int k;
	scanf("%d", &k);

	int outcome = 0; 
	outcome = get_minimum_number_with_k_occurences(arr, n, k);


	/* this is the (performance) test code, please don't touch it */

	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("minimum number of K occurences is %d\n", outcome);
#ifdef TEST_TIME
	printf("time needed was %f seconds\n", time_taken);
#endif
	return 0;
}

int get_minimum_number_with_k_occurences(int arr[], int n, int k) {
	int smallest = -1;

	for (int i = 0; i < n; i++) {
        if ((arr[i] > 0) && (arr[i] != smallest)) {
            // set count to 1 as number is present at least once
            int count = 1;
            for (int j = i + 1; j < n; j++){
                if (arr[i] == arr[j])
                    count += 1;
			}
            // If frequency of number is equal to 'k'
            if (count == k){
				if(smallest == -1){
					smallest = arr[i];
				}
				else{
					if(smallest > arr[i])
						smallest = arr[i];
				}
			}
        }
    }
	return smallest;
}
