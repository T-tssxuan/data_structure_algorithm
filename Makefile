all: ds al 

ds:
	cd data_structure && make
al:
	cd algorithm && make

.PHONY: clean

clean:
	rm */*.out

