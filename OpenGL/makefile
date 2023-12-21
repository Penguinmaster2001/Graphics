
main: main.o glad.o
	g++ -Wall main.o glad.o -o main.exe

main.o: main.cpp main.h
	g++ -Wall -c main.cpp main.h

glad.o: glad.c
	g++ -Wall -c glad.c

clean:
	rm *.o main.exe
