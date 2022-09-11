#include <stdio.h>

void sortIntegers(int aNew[]) {
	int temp;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3 - i - 1; j++)
		{
			if (aNew[j] > aNew[j + 1]) {
				temp = aNew[j];
				aNew[j] = aNew[j + 1];
				aNew[j + 1] = temp;
			}
		}
	}

}

void calcMedian(int a[]) {
	printf("\nmedian: %d", a[1]);
	
}


int main() {

	int a[3];

	for (int i = 0; i < 3; i++) {

		printf("Enter an integer: ");
		if (scanf("%d", &a[i]) != 1) {
			printf("INVALID INPUT");
			exit(0);
		}
	}


	sortIntegers(a); //To sort the array of integers

	calcMedian(a); // To calculate the median

	return(0);

}