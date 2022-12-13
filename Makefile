CC = gcc
CC_OPTS = -Wall
EXE = recherche

.SUFFIXES = .h .c .o
OBJS = main.o error.o 

all: clean build

clean:
	rm -f $(EXE)

build: link

link: compile
	$(CC) *.o -o $(EXE)

compile: $(OBJS)

.c.h.o:
	$(CC)  $(CC_OPTS) -c $*.c

test: unitaire integrations

integrations:

unitaire:
