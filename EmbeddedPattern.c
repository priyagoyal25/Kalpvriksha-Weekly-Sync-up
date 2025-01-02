
// Enter no of rows: 10
// \********/
// *\******/*
// **\****/**
// ***\**/***
// ****\/****
// ****/\****
// ***/**\***
// **/****\**
// */******\*
// /********\ 

#include <stdio.h>

int main()
{	
	int n;
	printf("Enter no of rows: ");
    scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		
		for (int j = 1; j <= n; j++) {
			
			if (i == j || i + j == (n + 1)) {
				if (i + j == (n + 1)) {
					printf("%c", '/');
				}
				else {
					printf("%c",'\\');
				}
			}
			else
				printf("%c", '*');
		}
		printf("\n");
	}

	return 0;
}

