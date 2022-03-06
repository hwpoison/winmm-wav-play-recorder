CC=gcc
TARGET=recorder.exe
CFLAGS= -O3 -lwinmm

all: recorder

recorder: wavutils.o 
	$(CC) recorder.c wavutils.o -o $(TARGET) $(CFLAGS)

clean:
	del wavutils.o