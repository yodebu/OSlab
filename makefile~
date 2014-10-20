CC=g++

.SUFFIXES: .c .o

.cc.o:
	$(CC) -g -c $*.c

all: osfile

osfile: main.o half.o square.o twice.o
	$(CC) -o osfile main half square twice

clean : 
	rm -f *.o 

main.o: main.c
half.o: half.c
square.o: square.c
twice.o: twice.c  
