OBJS := JSON.o Character.o Hero.o main.o
CC := g++-10
PNAME := a.out
TESTUNITS := units/ironman.json units/hulk.json
PUNITS := ./a.out $(TESTUNITS)

CFLAGS := -std=c++17 -Wall -Werror -lstdc++fs
CHFLAGS := --enable=warning,style,performance --output-file=report.txt
CHWARFLAGS := --enable=warning --error-exitcode=1
MEMFLAGS := --error-exitcode=1 --leak-check=full

IODIFF := ./run_test.sh
DOXCONF := doxconf
GTEST := test/runTests

build:
	$(CC) $(CFLAGS) -o $(PNAME) $(OBJS)

JSON.o:
	$(CC) $(CFLAGS) -c JSON.cpp JSON.h

Character.o:
	$(CC) $(CFLAGS) -c Character.cpp Character.h JSON.h

Hero.o:
	$(CC) $(CFLAGS) -c Hero.cpp Hero.h Character.h JSON.h

main.o:
	$(CC) $(CFLAGS) -c main.cpp Character.h JSON.h Hero.h

sca:
	cppcheck *.cpp $(CHFLAGS)

sca_warning:
	cppcheck *.cpp $(CHWARFLAGS)

memtest:
	valgrind $(MEMFLAGS) $(PUNITS)

gtest:
	$(GTEST)

io_diff_check:
	$(IODIFF)

documentation:
	doxygen $(DOXCONF)
