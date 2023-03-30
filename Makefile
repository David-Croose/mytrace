all:
	gcc -g -no-pie -finstrument-functions  test.c mytrace.c -o test

clean:
	rm -f test
