

#We have to switch off these default rules
%.c: %.y
%.c: %.l


lexertester: lex.yy.c lexertester.c pasm.tab.h utils.c utils.h ast.h
	gcc -o lexertester lexertester.c lex.yy.c utils.c

bisontester: lex.yy.c bisontester.c pasm.tab.h utils.c utils.h ast.h ast.c
	gcc -o bisontester bisontester.c lex.yy.c pasm.tab.c utils.c ast.c


transformtester: lex.yy.c transformtester.c pasm.tab.h utils.c utils.h ast.h ast.c symboltable.h symboltable.c machinecodes.c machinecodes.h
	gcc -o transformtester -Wall -O1 transformtester.c lex.yy.c pasm.tab.c utils.c ast.c symboltable.c machinecodes.c 

lex.yy.c: pasm.flex pasm.tab.h
	flex pasm.flex

pasm.tab.h: pasm.y
	bison -d pasm.y

.PHONY: clean
clean:
	rm lex.yy.c lexertester bisontester transformtester pasm.tab.h pasm.tab.c

.PHONY: test
test: lexertester bisontester transformtester
	./lexertester < test1.txt
	echo "next"
	./bisontester < test2.txt
	echo "next"
	./bisontester < test3.txt

