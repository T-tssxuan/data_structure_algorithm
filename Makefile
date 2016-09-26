files=$(wildcard *cpp)
prog=$(patsubst %.cpp,%,$(files))

all: $(prog)

%: %.cpp
	g++ -std=c++14 $< -o $@.out

