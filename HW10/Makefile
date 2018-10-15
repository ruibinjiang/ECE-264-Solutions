# ***
# *** Please modify this file as required
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFALGS = -DTEST_MAINFUNC -DTEST_FUNCGIVEN -DTEST_IMGTOGRAY -DTEST_HEADERVALID -DTEST_BMPOPENFILE -DTEST_BMPWRITEFUNC -DTEST_BMPFREEFUNC

SRCS = hw10.c bmpimage.c bmpfunc.c
OBJS = $(SRCS:%.c=%.o)

hw10: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o hw10

testmemory: $(TARGET)
	$(VAL) --log-file=memcheck1.txt ./hw06 inputs/test1.bin output1.bin
	$(VAL) --log-file=memcheck2.txt ./hw06 inputs/test2.bin output2.bin
	$(VAL) --log-file=memcheck3.txt ./hw06 inputs/test3.bin output3.bin
# Test memory leaks for all inputs and outputs

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

testall: test1 test2 test3

test1: hw10
	./hw10 exampleImages/CondProb.bmp CondProb.bmp
	diff CondProb.bmp expectedImages/expectedCondProb.bmp

test2: hw10
	./hw10 inputs/test2.bin output2.bin
	diff output2.bin expected/expected2.bin

test3: hw10
	./hw10 inputs/test3.bin output3.bin
	diff output3.bin expected/expected3.bin

clean: # remove all machine generated files
	rm -f hw10 *.o *.txt *.bin
