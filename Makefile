CC=gcc
STACK?=-DTEST_STACK
CFLAGS=-fopenmp $(STACK)
LDFLAGS=-fopenmp

all: test test_omp

test.o: test.c
	$(CC) -c -Wall $< -o $@

test_omp.o: test_omp.c
	$(CC) $(CFLAGS) -c -Wall $< -o $@

test: test.o
	$(CC) $< -o $@

test_omp: test_omp.o
	$(CC) $(LDFLAGS) $< -o $@

clean:
	rm -f *.o test test_omp
