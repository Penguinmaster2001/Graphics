
CC = g++
CPPFLAGS = -Wall
LDFLAGS = -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl

main.exe: main.o glad.o shader.o
	$(CC) $^ $(CPPFLAGS) $(LDFLAGS) -o $@

main.o: main.cpp main.h
	$(CC) $(CPPFLAGS) -c $<

glad.o: glad.c glad.h
	$(CC) -c $<

shader.o: shader.cpp shader.h
	$(CC) $(CPPFLAGS) -c $<

.PHONY: clean
clean:
	rm *.o *.gch main.exe

-include $(wildcard *.d)
