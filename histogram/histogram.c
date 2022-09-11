#include <stdio.h>

int calcMain(int cValue, int c, int hNum) {

	if (cValue != 1 || c > 100000 || c < 0) { //check for wrong inputs
		printf("INVALID INPUT");
		exit(0);
	}

	if (c > hNum) {
		hNum = c;
	}

	return hNum;

}

int main() {

	unsigned int a = 0, b = 0, c = 0, d = 0, hNum = 0;

	printf("Input A: ");
	int cValue = scanf("%u", &a);
	hNum = calcMain(cValue, a, hNum);

	printf("Input B: ");
	cValue = scanf("%i", &b);
	hNum = calcMain(cValue, b, hNum);

	printf("Input C: ");
	cValue = scanf("%i", &c);
	hNum = calcMain(cValue, c, hNum);

	printf("Input D: ");
	cValue = scanf("%i", &d);
	hNum = calcMain(cValue, d, hNum);

	for (int i = hNum; i > 0 ; i--) { //loop to display histogram

		if (a == i) {
			printf("%2s", "X");
			a--;
		} 
		else 
			printf("%2s", " ");

		if (b == i) {
			printf("%2s", "X");
			b--;
		}
		else
			printf("%2s", " ");

		if (c == i) {
			printf("%2s", "X");
			c--;
		}
		else
			printf("%2s", " ");

		if (d == i) {
			printf("%2s", "X");
			d--;
		}
		else
			printf("%2s", " ");

		printf("\n");

	}

	printf("----------\n");
	printf(" A B C D");

	return(0);

}