if [ -z $1 ]
then
filename=test.c
else
filename=$1
fi
lex lex.l 
yacc -v yacc.y
cc y.tab.c -ll
./a.out $filename
