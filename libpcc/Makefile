COMPILER=c++

FLAGS=-std=c++11 -Wall -Werror

INCLUDES=-Iinclude

all: libpcc.a

.PHONY: all clean

libpcc.a: pcc.o
	ar rvs libpcc.a pcc.o

pcc.o:
	$(COMPILER) $(FLAGS) $(INCLUDES) -c pcc.cpp

clean:
	rm -f *.o libpcc.a
