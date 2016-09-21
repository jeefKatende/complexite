Submax: main.o submax.o
	gcc -o submax submax.o main.o

main.o : main.c submax.h
	gcc -o main.o -c main.c -Wall -ansi -pedantic

submax.o : submax.c
	gcc -o submax.o -c submax.c -W -Wall -ansi -pedantic

clean :
	rm -rf *.o

mrproper : clean
	rm -rf submax
	clear