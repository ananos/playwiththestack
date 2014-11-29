#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

#include <omp.h>

int main (int argc, char ** argv)
{
	int i;
	int n = atoi(argv[1]);
	struct rlimit limit;

#ifdef TEST_STACK
	float a[n];
#else
	float * a=malloc(n*sizeof(float));
#endif
	fprintf(stderr, "Starting test\n");

	getrlimit (RLIMIT_STACK, &limit);
	fprintf (stderr, "Stack Limit = %ld and %ld max\n", limit.rlim_cur, limit.rlim_max);
	limit.rlim_max=n * sizeof(float);
	setrlimit (RLIMIT_STACK, &limit);
	fprintf (stderr, "Stack Limit = %ld and %ld max\n", limit.rlim_cur, limit.rlim_max);

	fprintf(stderr, "n:%d, sizeof(a) = %lu, omp_threads:%d \n", n, sizeof(a), omp_get_num_threads());
	for (i=0;i<n;i++) {
		a[i] = 0.01 * i;
		printf("%.2f ", a[i]);
	}
	printf("\n");

	#pragma omp parallel for firstprivate(a) 
	for (i=0;i<n;i++) {
		a[i]=0;
		printf("%.2f ",a[i]);
	}
	fprintf(stderr, "n:%d, sizeof(a) = %lu, omp_threads:%d \n", n, sizeof(a), omp_get_num_threads());

	printf("\n");

	for (i=0;i<n;i++) 
		printf("%.2f ",a[i]);

	printf("\n");
	return 0;
}
