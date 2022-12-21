CC = gcc
CC_OPTS = -Wall -std=c11
EXE = recherche
EXE_TEST = recherche_test

.SUFFIXES = .h .c .o
OBJS = main.o erreur.o list.o fichier.o
OBJS_TESTS = main_test.o list_test.o list.o

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
	rm -f *test.o
	./recherche_test

build_test: $(OBJS_TESTS)
	$(CC) $^ -lcunit -o $(EXE_TEST)
	