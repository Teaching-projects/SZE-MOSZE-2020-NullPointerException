OBJS := Hero.o AdvancedHero.o JsonParser.o main.o
CC := g++
PNAME := a.out
TESTUNITS := units/ironman.json units/hulk.json
PUNITS := ./a.out $(TESTUNITS)

CFLAGS := -std=c++17 -Wall -Werror
CHFLAGS := --enable=warning,style,performance --output-file=report.txt
CHWARFLAGS := --enable=warning --error-exitcode=1
MEMFLAGS := --error-exitcode=1 --leak-check=full

IODIFF := ./run_test.sh
DOXCONF := doxconf
GTEST := test/runTests

build:
	$(CC) $(CFLAGS) -o $(PNAME) $(OBJS)

Hero.o:
	$(CC) $(CFLAGS) -c Hero.cpp

AdvancedHero.o:
	$(CC) $(CFLAGS) -c AdvancedHero.cpp

JsonParser.o:
	$(CC) $(CFLAGS) -c JsonParser.cpp

main.o:
	$(CC) $(CFLAGS) -c main.cpp

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

doxygen:
	doxygen $(DOXCONF)
