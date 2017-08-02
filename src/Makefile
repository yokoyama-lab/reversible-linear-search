main: stack.o search.o main.o
	cc -o $@ $^

test: main
	./main < ../test/random_succeed.txt
	./main < ../test/random_succeed_2.txt
	./main < ../test/random_fail.txt
	./main < ../test/sorted_succeed.txt
	./main < ../test/sorted_succeed_2.txt
	./main < ../test/sorted_fail.txt

clean:
	rm -f *.o main

%.o: %.c %.h
	cc -c -o $@ $<
