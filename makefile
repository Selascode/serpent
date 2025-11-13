SRCDIR=src
LIBDIR=lib
BINDIR=bin
TESTDIR = tests
INCLUDEDIR=include
CC = gcc
AR = ar
CFLAGS=-Wall -pedantic -g -I$(INCLUDEDIR) 
LDFLAGS=-Llib -lncurses -lcunit -lc
EXEC=$(BINDIR)/serpent
TESTS = tests
MODULES = $(SRCDIR)/coordonnee.o $(SRCDIR)/direction.o $(SRCDIR)/serpent.o $(SRCDIR)/jeu.o $(SRCDIR)/interface.o
all :  $(EXEC) 

$(EXEC): $(MODULES) $(SRCDIR)/main.o
	$(CC) -o $@ $^ -lsdd $(LDFLAGS)

$(TESTS) : $(TESTDIR)/test_coordonnee $(TESTDIR)/test_direction $(TESTDIR)/test_serpent

$(TESTDIR)/test_% :  $(MODULES) $(SRCDIR)/test_%.o
	$(CC)  -o $@ $^ -lsdd $(LDFLAGS)


$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS) 

clean :
	rm -rf $(BINDIR)/*
	rm -rf $(TESTDIR)/*
	rm -rf $(LIBDIR)/*
	rm -rf $(SRCDIR)/*.o
