%{
	#include<stdio.h>
	#include<ctype.h>
	#include<string.h>
	#include"codeconst.h"
	char stack[50][10];
	int scount=0;
	int tcount=0;
	int icont=0;
	int cflag=0;
	int regs[26];
	char num[20];
	int ecount=0;
	FILE *fd,*fc;
	int  base;
%}

%start  st
%token CHAR SHORT INT FLOAT LONG DOUBLE
%token IDEN ICON SEMI NOP LC RC LP RP COMMA EQUAL
%token IF ELSE VOID WHILE RELOP EQUOP
%token FCON UNOP QUEST ELLIPSIS COLON
%left  OR
%left  AND
%left  OROR
%left  ANDAND
%left  PLUS  MINUS
%left  STAR  DIVOP
%left  UMINUS      /*  supplies  precedence  for  unary  minus  */

%%      /*  beginning  of  rules  section  */

st   :    rtype NAME LP RP LC list RC {printf("Assembly code SUCCESSFULLY produced\n");}
     |    rtype NAME RP LP LC list RC {yyerror("Incorrect order of brackets");}
     ;

rtype:    VOID
     |    INT
     |    CHAR
     |		{yyerror("Main must have return type. If none then write VOID");}
     ;

list :    stmt A		
     ;

A    :    stmt A
     |	  
     ;

stmt :    Datatype VList SEMI 
     |    SEMI
     |    IF LP expr RP stmt 
     |    IF LP expr RP stmt ELSE stmt 
     |    WHILE LP expr RP stmt	{fprintf(fc,"\tjmp wlbl%d\nlbl%d:\n",stk1[--wlbl],stk[--lbl]);}
     |    LC list RC  		
     |    expr SEMI	{if(cflag){fprintf(fc,"\tjmp lbl%d\nlbl%d:\nlbl%d:\n",lcount-1,stk[--lbl],stk[--lbl]);stk[lbl++]=lcount++;cflag=0;}}
     |    Datatype VList	{yyerror("Missing ';'");}
     |    IF expr RP stmt	{yyerror("Missing '(' in IF Construct");}
     |    IF LP expr stmt	{yyerror("Missing ')' in IF Construct");}
     |    IF expr RP stmt	{yyerror("Missing '(' in IF-ELSE Construct");}
     |    IF LP expr stmt	{yyerror("Missing ')' in IF-ELSE Construct");}
     |    error ';'  {yyerror("Expression syntax error");}
     ;

Datatype: CHAR
	| SHORT	
	| INT		
        | FLOAT         {yyerror("FLOAT: Datatype not supported");}
	| LONG          {yyerror("LONG: Datatype not supported");}        
	| DOUBLE	{yyerror("DOUBLE: Datatype not supported");}
	| error ';'	{yyerror("Datatype error");}
	;

VList:    DecAs B	
     ;

DecAs:    NAME EQUAL ICON  {fprintf(fd," %s\n",yytext);}
     |    NAME EQUAL MINUS ICON %prec MINUS	
		{
			sprintf(num,"%d",65535-atoi(yytext));
			printf("%s\n",num);
			fprintf(fd," %s\n",num);}
     |    NAME EQUAL EQUAL ICON {yyerror("Assignment operator required");} 
     |    NAME		
     |    NAME EQUAL	{yyerror("Value with which to initialize required");}
     |    error ';'     {yyerror("Decl Syntax Error");}
     ;

B    :    COMMA DecAs B  
     |    DecAs B  {yyerror("Missing comma");}
     |			
     |    error ';' {yyerror("Declaration syntax error");}
     ;

expr :    NAME EQUAL expr	{gen_code(ASSIGN,pop(),pop());}
     |    logic	
     |
     ;

logic:    logic OR logic
     |    logic AND logic
     |    logic OROR logic
     |    logic ANDAND logic 
     |    rel
     ;

rel  :    relA RELOP relB {gen_code(CMP,pop(),pop());}
     |    relA EQUOP relB {gen_code(CMP,pop(),pop());}
     |    bin
     ;

relA :    relB
     ;

relB :    bin
     ;

bin  :    bin PLUS binterm {gen_code(ADD,pop(),pop());} 
     |    bin MINUS binterm {gen_code(SUB,pop(),pop());}
     |    binterm
     ;

binterm:  binterm STAR binfact {gen_code(MUL,pop(),pop());}
     |    binterm DIVOP binfact {gen_code(DIV,pop(),pop());}
     |    binfact
     ;

binfact:  LP bin RP
     |    MINUS binfact  %prec MINUS
     |    NAME			
     |    ICON			{	sprintf(str,"iconst%d",icont++);
					push(str);
					fprintf(fd,"\t%s dw %s\n",str,yytext);
				}
     ;
NAME :    IDEN 			{push(yytext);}

%%
#include"lex.yy.c"
extern FILE *yyin;
yyerror(char *s)
{
        fprintf(stderr,"%3d\t%s\n",lineno,s);
	ecount++;
}
void push(char *s)
{
	strcpy(stack[scount++],s);
}
char * pop()
{
	return stack[--scount];
}
void gen_code(int type,char *arg1,char *arg2)
{
	char app[3],dum[]="tmp";
	switch(type)
	{
		case ADD:
			fprintf(fc,"\t;ADD\n");
			fprintf(fc,"\tlea si,%s\n",arg1);
			fprintf(fc,"\tlea di,%s\n",arg2);
			fprintf(fc,"\tmov ax,[si]\n");
			fprintf(fc,"\tadd ax,[di]\n");
			sprintf(app,"%d",tcount++);
			strcat(dum,app);
			fprintf(fc,"\tlea di,%s\n",dum);
			fprintf(fc,"\tmov [di],ax\n");
			push(dum);
			break;
		case SUB:
			fprintf(fc,"\t;SUB\n");
			fprintf(fc,"\tlea si,%s\n",arg1);
			fprintf(fc,"\tlea di,%s\n",arg2);
			fprintf(fc,"\tmov ax,[si]\n");
			fprintf(fc,"\tsub ax,[di]\n");
			sprintf(app,"%d",tcount++);
			strcat(dum,app);
			fprintf(fc,"\tlea di,%s\n",dum);
			fprintf(fc,"\tmov [di],ax\n");
			push(dum);
			break;
		case MUL:
			fprintf(fc,"\t;MUL\n");
			fprintf(fc,"\tlea si,%s\n",arg1);
			fprintf(fc,"\tlea di,%s\n",arg2);
			fprintf(fc,"\tmov ax,[si]\n");
			fprintf(fc,"\tmul ax,[di]\n");
			sprintf(app,"%d",tcount++);
			strcat(dum,app);
			fprintf(fc,"\tlea di,%s\n",dum);
			fprintf(fc,"\tmov [di],ax\n");
			push(dum);
			break;
		case DIV:
			fprintf(fc,"\t;DIV\n");
			fprintf(fc,"\tlea si,%s\n",arg1);
			fprintf(fc,"\tlea di,%s\n",arg2);
			fprintf(fc,"\tmov ax,[si]\n");
			fprintf(fc,"\tdiv ax,[di]\n");
			sprintf(app,"%d",tcount++);
			strcat(dum,app);
			fprintf(fc,"\tlea di,%s\n",dum);
			fprintf(fc,"\tmov [di],ax\n");
			push(dum);
			break;
		case ASSIGN:
			fprintf(fc,"\t;ASSIGN\n");
			fprintf(fc,"\tlea si,%s\n",arg1);
			fprintf(fc,"\tlea di,%s\n",arg2);
			fprintf(fc,"\tmov ax,[di]\n");
			fprintf(fc,"\tmov [si],ax\n");
			break;
		case CMP://CMP EQUAL
			fprintf(fc,"\t;CMP\n");
			fprintf(fc,"\tlea si,%s\n",arg1);
			fprintf(fc,"\tlea di,%s\n",arg2);
			fprintf(fc,"\tmov ax,[si]\n");
			fprintf(fc,"\tcmp ax,[di]\n");
			if(otype==EQ)
			{
				stk[lbl++]=lcount;
				fprintf(fc,"\tjnz lbl%d\n",lcount++);
			}
			if(otype==NE)
			{
				stk[lbl++]=lcount;
				fprintf(fc,"\tjz lbl%d\n",lcount++);
			}
			if(otype==GT)
			{
				fprintf(fc,"\t;CMP GT\n\tjz lbl%d\n\tjc lbl%d\n",lcount,lcount);
				stk[lbl++]=lcount++;
			}
			if(otype==GE)
			{
				fprintf(fc,"\t;CMP GE\n\tjz lbl%d\n",lcount++);
				fprintf(fc,"\tjc lbl%d\n",lcount);
				stk[lbl++]=lcount++;
				fprintf(fc,"lbl%d:\n",lcount-2);
				stk[lbl++]=lcount++;
				stk[-lbl];
			}
			if(otype==LT)
			{
				fprintf(fc,"\t;CMP LT\njz lbl%d\n\tjnc lbl%d\n",lcount,lcount);
				stk[lbl++]=lcount++;
			}
			if(otype==LE)
			{
				fprintf(fc,"\t;CMP LE\n\tjz lbl%d\n",lcount++);
				fprintf(fc,"\tjnc lbl%d\n",lcount);
				stk[lbl++]=lcount++;
				fprintf(fc,"lbl%d:\n",lcount-2);
			}
			break;
	}
}
void copy_fn_defn()
{
	char str[30],str1[30];
	FILE *fp;
	fp=fopen("proc.asm","r");
	fprintf(fc,"\n");
	while(feof(fp)==0)
	{
		strcpy(str1,str);
		fgets(str,100,fp);
		if(strcmp(str,str1)!=0)
		fprintf(fc,"%s",str);
	}
	fclose(fp);
}
void copy_code2data()
{
	char str[30],str1[30];
	fclose(fc);
	fc=fopen("code.asm","r");
	while(feof(fc)==0)
	{
		strcpy(str1,str);
		fgets(str,100,fc);
		if(strcmp(str,str1)!=0)
		fprintf(fd,"%s",str);
	}
}
void add_tmp_defn(int count)
{
	int i;
	for(i=0;i<=count;i++)
	fprintf(fd,"\ttmp%d db ?\n");
}
int main(int argc,char *argv[])
{
	char str[30],str1[30];
	FILE *fp;
	fd=fopen("data.asm","w");
	fc=fopen("code.asm","w");
	fprintf(fd,".model small\n");
	fprintf(fd,".stack 80h\n");
	fprintf(fd,".data\n");
	fprintf(fc,".code\n");
	fprintf(fc,"\tmov ax,@data\n");
	fprintf(fc,"\tmov ds,ax\n");
	fprintf(fc,"\tmov es,ax\n");
	//fprintf(fc,"\tcall clear\n");
        ++argv; --argc;
        if(argc>0)
        yyin=fopen(argv[0],"r");
        else
        yyin=stdin;
        yyparse();
	fprintf(fc,"\tcall exittodos\n");
	fprintf(fc,"\tint 3h\n");
	fp=fopen("proc.asm","r");
	fprintf(fc,"\n");
	while(feof(fp)==0)
	{
		strcpy(str1,str);
		fgets(str,100,fp);
		if(strcmp(str,str1)!=0)
		fprintf(fc,"%s",str);
	}
	fclose(fp);
	fprintf(fc,"end\n");
	add_tmp_defn(tcount-1);
	copy_code2data();
	fclose(fd);
	fclose(fc);
	if(ecount!=0)
	printf("Number of Errors: %d\n",ecount);
        return 0;
}

