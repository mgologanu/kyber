CFLAGS +=  -O3 -Wall -mavx2 -mfma -march=native -fomit-frame-pointer

CC = gcc 

LIB =

LIB_SOURCES = pass_m.c  modular_operations_m.c roots_m.c ntt_recursive_m.c

LIB_OBJECTS =  $(LIB_SOURCES:.c=.o)

UNITTESTS_LIST = $(wildcard test/test_*.c)
UNITTESTS= $(UNITTESTS_LIST:.c=.test)

.SUFFIXES: .c .test

.PHONY: all check clean

all: libntt_3329.a


libntt_3329.a: $(LIB_OBJECTS) 
	$(AR) rc $@ $^
	ranlib $@

check: libntt_3329.a $(UNITTESTS) 
	$(info $(UNITTESTS))
	for t in $(UNITTESTS); do ./$$t ; done 

clean:
	rm libntt_3329.a
	rm -f *.o *~
	rm -f test/*.test test/*.o test/*~ 

.c.o:   $< 
	$(CC) $(CFLAGS) -c $< -o $@

.c.test: $< 
	$(CC) $(CFLAGS) -g -o $@ $< -I. -L. -lntt_3329 $(LIB) -lm
