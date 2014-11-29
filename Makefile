all: test

test.o: test.c
	$(CC) -c -Wall $< -o $@ -O0

test: test.o
	$(CC) $< -o $@

clean:
	rm -f *.o test
