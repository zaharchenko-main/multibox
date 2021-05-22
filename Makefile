all:build

build:
	gcc -s -O3 -static src/*.c -o multibox

clean:
	rm -rf libs obj
