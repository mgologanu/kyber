CFLAGS +=  -O3 -Wall -mavx2 -mfma -march=native -fomit-frame-pointer

CC = gcc 

LIB =

LIB_SOURCES = pass.c  modular_operations.c roots.c

LIB_OBJECTS =  $(LIB_SOURCES:.c=.o)

UNITTESTS_LIST = $(wildcard test/test_*.c)
UNITTESTS= $(UNITTESTS_LIST:.c=.test)

.SUFFIXES: .c .test

.PHONY: all check clean

all: libntt_7681.a


libntt_7681.a: $(LIB_OBJECTS) 
	$(AR) rc $@ $^
	ranlib $@

check: libntt_7681.a $(UNITTESTS) 
	$(info $(UNITTESTS))
	for t in $(UNITTESTS); do ./$$t ; done 

clean:
	rm libntt_7681.a
	rm -f *.o *~
	rm -f test/*.test test/*.o test/*~ 

.c.o:   $< 
	$(CC) $(CFLAGS) -c $< -o $@

.c.test: $< 
	$(CC) $(CFLAGS) -g -o $@ $< -I. -L. -lntt_7681 $(LIB) -lm
