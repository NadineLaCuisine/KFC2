CC=/usr/bin/g++
# CC=g++
#CC=clang++
CFLAGS=  -Wall  -Ofast -std=c++11 -march=native -flto -Wfatal-errors -pipe -funit-at-a-time -fomit-frame-pointer
LDFLAGS=-flto -lpthread


ifeq ($(gprof),1)
CFLAGS=-std=c++0x -pg -O4   -march=native
LDFLAGS=-pg
endif

ifeq ($(valgrind),1)
CFLAGS=-std=c++0x -O4 -g
LDFLAGS=-g
endif



EXEC=kfc  

all: $(EXEC)


utils.o: utils.cpp utils.h
	$(CC) -o $@ -c $< $(CFLAGS)

kfc: main.o  utils.o
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: main.cpp  utils.h
	$(CC) -o $@ -c $< $(CFLAGS)


clean:
	rm -rf *.o
	rm -rf $(EXEC)


rebuild: clean $(EXEC)
