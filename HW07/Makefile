# ***
# *** Please modify this file as required
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFALGS = -DTEST_MERGE -DTEST_MERGESSORT -DTEST_MERGESORT 

SRCS = main.c
OBJS = $(SRCS:%.c=%.o)

hw07: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o hw07

testmemory: $(TARGET)
	$(VAL) --log-file=memcheck1.txt ./hw06 inputs/test1.bin output1.bin
# Test memory leaks for all inputs and outputs

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

testall: test1 test2 test3

test1: hw07
	./hw07 Input/Test1 Output1
	diff Output1 Expected/Expected1

test2: hw07
	./hw07 Input/Test2 Output2
	diff Output2 Expected/Expected2

test3: hw07
	./hw07 Input/Test3 Output3
	diff Output3 Expected/Expected3

clean: # remove all machine generated files
	rm -f hw07 *.o Output?
