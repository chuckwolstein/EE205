all:
	cat test.txt

double-cat:
	cat test.txt
	cat test.txt

quad-cat: double-cat
	cat test.txt
	cat test.txt

did-change: ./test.txt
	cat test.txt

compile:  ./main.cpp
	g++ main.cpp

run:  compile
	./a.out
