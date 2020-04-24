
test: a.out
	./test.py

a.out: range.cpp
	g++ -g range.cpp
