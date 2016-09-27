files=$(wildcard *cpp)
prog=$(patsubst %.cpp,%.out,$(files))

all: $(prog)

%.out: %.cpp
	g++ -std=c++14 $< -o $@

.PHONY: clean

clean:
	rm *.out
