CC = gcc
CC_OPTS = -Wall
EXE = recherche
EXE_TEST = recherche_test

.SUFFIXES = .h .c .o
OBJS = main.o erreur.o list.o
OBJS_TESTS = main_test.o

all: clean build

clean:
	rm -f $(EXE)
	rm -f $(EXE_TEST)

build: link

link: compile
	$(CC) *.o -o $(EXE)

compile: $(OBJS)

.c.h.o:
	$(CC)  $(CC_OPTS) -c $*.c

test: build_test
	rm -f main_test.o
	./recherche_test

build_test: $(OBJS_TESTS)
	$(CC) $^ -o $(EXE_TEST)
	