include ./makefile.defines

PROGS= ListTest ListTestStruct \
	   StackTest StackTestStruct \
	   QueueTest QueueTestStruct

all: $(PROGS)

ListTest: ListTest.o
	$(CC) $(CFLAGS) list.c -o $@ $^

ListTestStruct: ListTestStruct.o
	$(CC) $(CFLAGS) list.c -o $@ $^

StackTest: StackTest.o
	$(CC) $(CFLAGS) list.c stack.c -o $@ $^

StackTestStruct: StackTestStruct.o
	$(CC) $(CFLAGS) list.c stack.c -o $@ $^
	
QueueTest: QueueTest.o
	$(CC) $(CFLAGS) list.c queue.c -o $@ $^

QueueTestStruct: QueueTestStruct.o
	$(CC) $(CFLAGS) list.c queue.c -o $@ $^

.PHONY: clean
clean:
	$(RM) $(PROGS) *.o

