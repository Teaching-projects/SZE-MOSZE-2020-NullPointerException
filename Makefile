OBJS := Hero.o AdvancedHero.o JsonParser.o main.o
CC := g++
CFLAGS := -std=c++17

build:
    $(CC) $(CFLAGS) -o a.out $(OBJS)

Hero.o:
    $(CC) $(CFLAGS) -c Hero.cpp

AdvancedHero.o:
    $(CC) $(CFLAGS) -c AdvancedHero.cpp

JsonParser.o:
    $(CC) $(CFLAGS) -c JsonParser.cpp

main.o:
    $(CC) $(CFLAGS) -c main.cpp
