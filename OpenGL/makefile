
CC = g++
CPPFLAGS = -Wall
LDFLAGS = -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl

main.exe: main.o glad.o
	$(CC) $^ $(CPPFLAGS) $(LDFLAGS) -o $@

main.o: main.cpp main.h
	$(CC) $(CPPFLAGS) -c $<

glad.o: glad.c glad.h
	$(CC) -c $<

.PHONY: clean
clean:
	rm *.o *.gch main.exe

-include $(wildcard *.d)
