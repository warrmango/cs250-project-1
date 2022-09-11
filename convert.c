#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

void clearArr(char* arr) {
	for (int i = 0; i < strlen(arr); i++) {
		arr[i] = '\0';
	}
}
int intpower(int a, int b) {
	int c = 1;
	for (int i = 0; i < b; i++) {
		c *= a;
	}
	return c;
}

void main(int argc, char** argv) {
	
	int i = 0;
	int j = 0;
	int k = 0;
	int dec = 0;
	int remainder = 0;
	int a = 0;
	int len = 0;
	char arr[13];
	if (argv[1] == NULL || argv[2] == NULL || argv[3] == NULL) {
		printf("Usage:  convert <basefrom> <baseto> <number>\n");
		return;
	}

	int basefrom = atoi(argv[1]);
	int baseto = atoi(argv[2]);
	bool isdigital = true;
	for (int k = 0; k < strlen(argv[3]); k++) {
		if (!isdigit(argv[3][k])) {
			isdigital = false;
		}
	}
	if (!isdigital) {
		printf("Number read in base %d: %s\n", basefrom, argv[3]);
		len = strlen(argv[3]);
		
		j = len - 1;
		for (j; j >= 0; j--) {
			i = len - 1 - j;
			if (isdigit(argv[3][j])) {
				dec += (int)(argv[3][j]) * intpower(basefrom, i);
			}
			else {
				dec += (int)(argv[3][j] - 55) * intpower(basefrom, i);
			}
		}
		printf("Converted to base 10: %d\n", dec);
		i = 0;
		int sum = 0; 
		clearArr(arr);
		if (baseto <= 10) {
			for (dec; dec != 0; i++) {
				remainder = dec % baseto;
				dec = dec / baseto;
				sum += remainder * intpower(10, i);
			}
			printf("Converted to base %d: %d\n", baseto, sum);
		}
		else {
			for (dec; dec != 0; i++) {
				remainder = dec % baseto;
				dec = dec / baseto;
				if (remainder > 9) {
					remainder += 55;
					*(arr + i) = remainder;
				}
				else {
					remainder += 48;
					*(arr + i) = remainder;
				}
			}
			printf("Converted to base %d: ", baseto);
			j = strlen(arr) - 1;
			for (j; j >= 0; j--) {
				printf("%c", arr[j]);
			}
			printf("\n");
		}
	}
	else {
		long b = atol(argv[3]);
		printf("Number read in base %d: %ld\n", basefrom, b);
		if (b % 10 >= basefrom) {
			printf("Wrong digit in number.\n");
			return;
		}
		for (b; b != 0; i++) {
			remainder = b % 10;
			b = b / 10;
			a += remainder * intpower(basefrom, i);
		}
		printf("Converted to base 10: %d\n", a);
		i = 0;
		clearArr(arr);
		if (baseto <= 10) {
			for (a; a != 0; i++) {
				remainder = a % baseto;
				a = a / baseto;
				b += remainder * intpower(10, i);
			}
			printf("Converted to base %d: %ld\n", baseto, b);
		}
		else {
			for (a; a != 0; i++) {
				remainder = a % baseto;
				a = a / baseto;
				if (remainder > 9) {
					remainder += 55;
					*(arr + i) = remainder;
				}
				else {
					remainder += 48;
					*(arr + i) = remainder;
				}
			}
			printf("Converted to base %d: ", baseto);
			j = strlen(arr) - 1;
			for (j; j >= 0; j--) {
				printf("%c", arr[j]);
			}
			printf("\n");
      }
    }
  }
