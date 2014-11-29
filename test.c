#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

int main (int argc, char ** argv)
{
	int i;
	int n = atoi(argv[1]);
	int a[n];
	struct rlimit limit;

	getrlimit (RLIMIT_STACK, &limit);
	printf ("\nStack Limit = %ld and %ld max\n", limit.rlim_cur, limit.rlim_max);
	printf("sizeof(a) = %lu ", sizeof(a));
	for (i=0;i<n;i++) {
		a[i] = i;
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
