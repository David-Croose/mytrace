all:
	gcc -g -no-pie -finstrument-functions  test.c mytrace.c -o test

lib:
	gcc -g -no-pie -finstrument-functions  mytrace.c -o libmytrace.a

clean:
	rm -f test libmytrace.a
