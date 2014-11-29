#include <stdio.h>

int main (int argc, char ** argv)
{

	int n = 0;
	int i;
	int a[n];

	printf("sizeof(a) = %d ", sizeof(a));
	n = atoi(argv[1]);
	for (i=0;i<n;i++) {
		a[i] = i;
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
