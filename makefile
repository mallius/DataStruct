include ./makefile.defines

PROGS=BiTreeTest \
      StackTest

all: $(PROGS)

BiTreeTest: BiTreeTest.o
	$(CC) $(CFLAGS) bitree.c -o $@ $^

StackTest: StackTest.o 
	$(CC) $(CFLAGS) list.c stack.c -o $@ $^

.PHONY: clean
clean:
	$(RM) $(PROGS) *.o

