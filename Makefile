CC=gcc
CPP=g++
CFLAGS=-I. -std=c++11 -g -O2
CPPFLAGS=-I. -std=c++11 -g -O2
#DEPS = klogparser.h
OBJ = src/klogparser.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.cpp $(DEPS)
	$(CPP) -c -o $@ $< $(CPPFLAGS)

klogparser: $(OBJ)
	$(CPP) -o $@ $^ $(CFLAGS)
