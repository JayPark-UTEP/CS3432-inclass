#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>

void swap(int v[], size_t k)
{
    int temp;
    temp = v[k];
    v[k] = v[k+1];
    v[k+1] = temp;
}

void sort(int v[], size_t n)
{
    size_t i, j;
    for (i = 0; i < n; i+=1) {
        for (j = i - 1; j >= 0 & v[j] > v[j+1]; j-=1) {
	    swap(v,j);
	}
    }
}

int main(int argc, char **argv)
{
    clock_t t;
    
    int print;
    size_t i, n;
    int values[1000000];

    if (argc != 3) {
        printf("Usage: %s <n> <pr> where <n> is the number of integers to sort and <pr> is 1 to print and 0 otherwise\n", argv[0]);
	exit(1);
    }
    n = atoi(argv[1]);   
    print = atoi(argv[2]);
    srand(time(0));
    for (i = 0; i < n; i++) {
        values[i] = rand();
        if (print)
            printf("%d\n", values[i]);
    }

    t = clock();

    sort(values, n);
    if (print) {
        printf("\nsorted:\n");
        for (i = 0; i < n; i++) 
            printf("%d\n", values[i]);
    }
    else 
        printf("values[0]: %d\n", values[0]);

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("\nQsort took %f seconds to execute \n", time_taken);


    return(0);
}
