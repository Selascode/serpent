SRCDIR=src
LIBDIR=lib
BINDIR=bin
TESTDIR = test
INCLUDEDIR=include
CC = gcc
AR = ar
CFLAGS=-Wall -pedantic -g
LDFLAGS=-lcunit -lm -lc
TESTS = $(TESTDIR)/gnTU

all :   $(TESTS)

$(TESTS) : $(SRCDIR)/gnTU.o $(LIBDIR)/liblistes.a $(LIBDIR)/libgrandNaturel.a
	$(CC)  -o $@ $< -llistes -lgrandNaturel -Llib $(LDFLAGS)

$(LIBDIR)/liblistes.a : $(SRCDIR)/ListeChaineeDeCaracteres.o 
	$(AR)  -r $@  $^

$(LIBDIR)/libgrandNaturel.a : $(SRCDIR)/GrandNaturel.o
	$(AR)  -r $@  $^

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDEDIR)  

clean :
	rm -rf $(BINDIR)/*
	rm -rf $(TESTDIR)/*
	rm -rf $(LIBDIR)/*
	rm -rf $(SRCDIR)/*.o
