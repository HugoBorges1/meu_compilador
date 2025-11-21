all:
	flex lexico.l
	bison -d sintatico.y
	clang++ -std=c++20 -g -O1 *.c -o cmp
