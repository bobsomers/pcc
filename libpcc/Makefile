COMPILER=c++
FLAGS=-std=c++11 -Wall -Werror

all: pcc.o
	ar rvs libpcc.a pcc.o

pcc.o:
	$(COMPILER) $(FLAGS) -c pcc.cpp
