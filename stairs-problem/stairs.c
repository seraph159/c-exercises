
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	unsigned int n;
	printf("Enter number of stairs: ");

	int cValue = scanf("%d", &n);


	if (cValue != 1 || n > 100000) { //check for wrong inputs
		printf("INVALID INPUT");
		exit(0);
	}

	printf("up stairs:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++)
			if (j == 0 && i == 0)
				printf("%*s", n, "X");
			else if (j == 0 && i > 0)
				printf("%*s", (n - i), "X");
			else
				printf("%s", "X");
		printf("\n");
	}


	printf("\ndown stairs:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i+1; j++)
			printf("%s", "X");
		printf("\n");
	}

	printf("\nup-down stairs:\n");
	int k = 1;
	for (int i = 0; i < n * 2; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (i % 2 == 0)
				if (j == 0 && i == 0)
					printf("%*s", (n), "X");
				else if (j == 0 && i > 0) {
					printf("%*s", (n - k), "X");
					k++;
				}
				else
					printf("%s", "X");
		}
		if (i % 2 == 0) 
			printf("\n");
	}


	return(0);
}