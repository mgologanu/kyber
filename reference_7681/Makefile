CFLAGS +=  -O3 -Wall -mavx2 -mfma -march=native -fomit-frame-pointer

CC = gcc 

LIB =

LIB_SOURCES = pass.c 

LIB_OBJECTS =  $(LIB_SOURCES:.c=.o)

UNITTESTS_LIST = $(wildcard test/test_*.c)
UNITTESTS= $(UNITTESTS_LIST:.c=.test)

.SUFFIXES: .c .test

.PHONY: all check clean

all: libzen3b.a


libzen3b.a: $(LIB_OBJECTS) 
	$(AR) rc $@ $^
	ranlib $@

check: libzen3b.a $(UNITTESTS) 
	$(info $(UNITTESTS))
	for t in $(UNITTESTS); do ./$$t ; done 

clean:
	rm libntt_7681.a
	rm -f *.o *~
	rm -f test/*.test test/*.o test/*~ 

.c.o:   $< 
	$(CC) $(CFLAGS) -c $< -o $@

.c.test: $< 
	$(CC) $(CFLAGS) -g -o $@ $< -I. -L. -lzen3b $(LIB) -lm
