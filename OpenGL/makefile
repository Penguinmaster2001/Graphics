
CC = g++
CPPFLAGS = -Wall
GLFLAGS = -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl

main: main.o glad.o
	$(CC) $(CPPFLAGS) $(GLFLAGS) main.o glad.o -o main.exe

main.o: main.cpp main.h
	$(CC) $(CPPFLAGS) $(GLFLAGS) -c main.cpp main.h

glad.o: glad.c glad.h
	$(CC) $(CPPFLAGS) $(GLFLAGS) -c glad.c glad.h

clean:
	rm *.o *.gch main.exe
