all:
	flex lexico.l
	bison -d sintatico.y
	clang++ -std=c++20 -g -O1 *.c -o cmp
	-./cmp programa_1.txt
	-./cmp programa_2.txt
	-./cmp programa_3.txt
	-./cmp programa_4.txt
	-./cmp programa_5.txt
	-./cmp programa_6.txt
	-./cmp programa_7.txt
	-./cmp programa_8.txt
	-./cmp programa_9.txt