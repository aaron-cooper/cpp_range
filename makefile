
test: a.out
	./test.py

a.out: main.cpp range.h
	g++ -g main.cpp
