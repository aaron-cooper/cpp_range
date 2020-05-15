
test: a.out
	./test.py

a.out: main.cpp range.h
	g++ -g -Wall main.cpp
