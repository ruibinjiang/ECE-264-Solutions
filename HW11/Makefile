# ***
# *** Please modify this file as required
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFALGS = -DTEST_MAIN -DTEST_FUNCGIVEN -DTEST_IMGTOGRAY -DTEST_ADAPTIVETHRESHOLDING -DTEST_HEADERVALID -DTEST_BMPOPENFILE -DTEST_WRITEFUNC -DTEST_BMPFREEFUNC

SRCS = hw11.c bmpimage.c bmpfunc.c
OBJS = $(SRCS:%.c=%.o)

hw10: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o hw11

testmemory: $(TARGET)
	$(VAL) --log-file=memcheck1.txt ./hw06 inputs/test1.bin output1.bin
	$(VAL) --log-file=memcheck2.txt ./hw06 inputs/test2.bin output2.bin
	$(VAL) --log-file=memcheck3.txt ./hw06 inputs/test3.bin output3.bin
# Test memory leaks for all inputs and outputs

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

testall: test1 test2 test3

test1: hw11
		./hw11 exampleImages/RV.bmp output1.bmp 5 2
		diff output1.bmp expectedImages/expectedRV.bmp

test2: hw11
		./hw11 exampleImages/RV2.bmp output2.bmp 3 2
		diff output2.bmp expectedImages/expectedRV2.bmp

test3: hw11
		./hw11 exampleImages/CondProb.bmp output3.bmp 1 2
		diff output3.bmp expectedImages/expectedCondProb.bmp

test4: hw11
		./hw11 exampleImages/RV2Small.bmp output4.bmp 11 2
		diff output4.bmp expectedImages/expectedRV2Small.bmp

clean:
		rm -f $(OBJS) $(TARGET) valgrind?.log header.imagesize output?.bmp
