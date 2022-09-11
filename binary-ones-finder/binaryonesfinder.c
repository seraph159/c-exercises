#include <stdio.h>

int main() {
	int arr[100], j = 0, i = 0;

	unsigned int num = 0 , numTemp = 0;

	printf("Enter a non-negative integer: ");

	int cValue = scanf("%i", &num);
	
	
	if (cValue != 1 || num > 1000000) { //check for wrong inputs
			printf("INVALID INPUT");
			exit(0);
	}

	numTemp = num;

	while (num > 0) {

		arr[j] = num % 2;
		num = num / 2;
		j++;

	}

	for (j = j - 1; j >= 0; j--)
	{
		if (arr[j] == 1) {
			i++;
		}
	}

	printf("\n%d has %d one(s) in its binary representation", numTemp, i);
	return 0;
}