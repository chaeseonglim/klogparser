CC=gcc
CPP=g++
CFLAGS=-I. -std=c++11
CPPFLAGS=-I. -std=c++11
#DEPS = klogparser.h
OBJ = src/klogparser.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.cpp $(DEPS)
	$(CPP) -c -o $@ $< $(CPPFLAGS)

klogparser: $(OBJ)
	$(CPP) -o $@ $^ $(CFLAGS)
