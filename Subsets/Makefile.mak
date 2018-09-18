
all: run

run: main.o subsets.o
	gcc -Wall main.o subsets.o -o run.exe
	
main.o: main.c subsets.h
	gcc -c -Wall main.c

subsets.o: subsets.c subsets.h
	gcc -c -Wall subsets.c
	
clean:
	rm -rf *.o *.exe


	
