MAKEFLAGS += --no-print-directory

all:compile build

compile:
	mkdir -p bin objs && cd objs && gcc -c ../src/*.c

build:
	gcc -s -O2 -static -Wall objs/*.o -o bin/multibox

clean:
	rm -rf bin libs obj objs
