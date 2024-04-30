#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int arr[], int n) {
	int i;
    for (i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int n = 10, i; // Change this to the number of unique random numbers you want
    int numbers[n];

    // Initialize the array with values from 1 to n
    for ( i = 0; i < n; i++) {
        numbers[i] = i + 1;
    }

    // Shuffle the array to get unique random numbers
    shuffle(numbers, n);

    // Print the unique random numbers
    for ( i = 0; i < n; i++) {
        printf("%d\n", numbers[i]);
    }

    return 0;
}

