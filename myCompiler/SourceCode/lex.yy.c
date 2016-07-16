# include "stdio.h"
# define U(x) x
# define NLSTATE yyprevious=YYNEWLINE
# define BEGIN yybgin = yysvec + 1 +
# define INITIAL 0
# define YYLERR yysvec
# define YYSTATE (yyestate-yysvec-1)
# define YYOPTIM 1
# define YYLMAX 200
# define output(c) putc(c,yyout)
# define input() (((yytchar=yysptr>yysbuf?U(*--yysptr):getc(yyin))==10?(yylineno++,yytchar):yytchar)==EOF?0:yytchar)
# define unput(c) {yytchar= (c);if(yytchar=='\n')yylineno--;*yysptr++=yytchar;}
# define yymore() (yymorfg=1)
# define ECHO fprintf(yyout, "%s",yytext)
# define REJECT { nstr = yyreject(); goto yyfussy;}
int yyleng; extern char yytext[];
int yymorfg;
extern char *yysptr, yysbuf[];
int yytchar;
FILE *yyin = {stdin}, *yyout = {stdout};
extern int yylineno;
struct yysvf { 
	int yystoff;
	struct yysvf *yyother;
	int *yystops;};
struct yysvf *yyestate;
extern struct yysvf yysvec[], *yybgin;

#line 2 "lex.l"
	#include<conio.h>
	#include<string.h>
	#include"symboltab.c"
	#include"const.h"
	int stk[20],stk1[20];
	int lbl=0,wlbl=0;
	int lineno=0;
	int pcount=1;
	int lcount=0,wlcount=0;
	int token=100;
	int dtype=0;
	int count=0;
	int fflag=0;
	int scope=0; /* 1-LOCAL 2-GLOBAL */
	int fexe=0;
	int p;
	int otype;
	char c,str[20],str1[10],idename[10];
	char a[100];
	void eatcom();
	void eatWS();
	int set(int);
	void check(char);
	void checkop();
	int chfunction(char *);
	int getArguments();
# define YYNEWLINE 10
yylex(){
int nstr; extern int yyprevious;
while((nstr = yylook()) >= 0)
yyfussy: switch(nstr){
case 0:
if(yywrap()) return(0); break;
case 1:

#line 40 "lex.l"
			eatcom();
break;
case 3:

#line 42 "lex.l"
	return STRING;
break;
case 4:

#line 43 "lex.l"
	printf("Adding missing \" to sting constant");
break;
case 5:

#line 44 "lex.l"
 case 6:

#line 45 "lex.l"
case 7:

#line 46 "lex.l"
	{strcpy(idename,yytext);return ICON;}
break;
case 8:

#line 47 "lex.l"
return FCON;
break;
case 9:

#line 49 "lex.l"
			{a[count++]='{';fexe=0;eatWS();return LC;}
break;
case 10:

#line 50 "lex.l"
			{a[count++]='(';eatWS();return LP;}
break;
case 11:

#line 51 "lex.l"
			{a[count++]='[';eatWS();return LB;}
break;
case 12:

#line 52 "lex.l"
			{check('{');eatWS();
					if(cflag)
					{
						fprintf(fc,"\tjmp lbl%d\nlbl%d:\n",lcount,stk[--lbl]);
						//stk[lbl++]=lcount++;
						fprintf(fc,"lbl%d:\n",stk[--lbl]);
						//stk[lbl++]=lcount++;
						printf("%d\n",stk[lbl]);
						cflag=0;
					}
					return RC;
				}
break;
case 13:

#line 64 "lex.l"
			{check('[');eatWS();return RB;}
break;
case 14:

#line 65 "lex.l"
			{check('(');eatWS();return RP;}
break;
case 15:

#line 66 "lex.l"
case 16:

#line 67 "lex.l"
case 17:

#line 68 "lex.l"
			return UNOP;
break;
case 18:

#line 69 "lex.l"
			{eatWS();return STAR;}
break;
case 19:

#line 70 "lex.l"
			{eatWS();return DIVOP;}
break;
case 20:

#line 71 "lex.l"
			{eatWS();return PLUS;}
break;
case 21:

#line 72 "lex.l"
			{eatWS();return MINUS;}
break;
case 22:

#line 73 "lex.l"
case 23:

#line 74 "lex.l"
			{checkop();return RELOP;}
break;
case 24:

#line 75 "lex.l"
			{checkop();return EQUOP;}
break;
case 25:

#line 76 "lex.l"
case 26:

#line 77 "lex.l"
			return EQUAL;
break;
case 27:

#line 78 "lex.l"
			return AND;
break;
case 28:

#line 79 "lex.l"
			return XOR;
break;
case 29:

#line 80 "lex.l"
			return OR;
break;
case 30:

#line 81 "lex.l"
			return ANDAND;
break;
case 31:

#line 82 "lex.l"
			return OROR;
break;
case 32:

#line 83 "lex.l"
			return QUEST;
break;
case 33:

#line 84 "lex.l"
			{eatWS();return COMMA;}
break;
case 34:

#line 85 "lex.l"
			return COLON;
break;
case 35:

#line 86 "lex.l"
			return ELLIPSIS;
break;
case 36:

#line 87 "lex.l"
{	dtype=set(2); eatWS();
					return SHORT;	}
break;
case 37:

#line 89 "lex.l"
	{	dtype=set(5); eatWS();
					return LONG;	}
break;
case 38:

#line 91 "lex.l"
		{	dtype=set(1); eatWS();
					return CHAR;	}
break;
case 39:

#line 93 "lex.l"
		{	dtype=set(2); eatWS();
					return SHORT;	}
break;
case 40:

#line 95 "lex.l"
		{	dtype=set(3); eatWS();
					return INT;	}
break;
case 41:

#line 97 "lex.l"
		{	dtype=set(4); eatWS();
					return FLOAT;	}
break;
case 42:

#line 99 "lex.l"
		{	dtype=set(5); eatWS();
					return LONG;	}
break;
case 43:

#line 101 "lex.l"
		{	dtype=set(6); eatWS();
					return DOUBLE;	}
break;
case 44:

#line 103 "lex.l"
			{	dtype=0;
					eatWS();
					return SEMI;}
break;
case 45:

#line 106 "lex.l"
			return AUTO;
break;
case 46:

#line 107 "lex.l"
			return BREAK;
break;
case 47:

#line 108 "lex.l"
			return CASE;
break;
case 48:

#line 109 "lex.l"
		return CONTINUE;
break;
case 49:

#line 110 "lex.l"
		return DEFAULT;
break;
case 50:

#line 111 "lex.l"
			return DO;
break;
case 51:

#line 112 "lex.l"
			{	cflag=3;
					eatWS();
				/*a	stk[lbl++]=lcount;
					fprintf(fc,"\tjmp lbl%d\nlbl%d:\n",lcount++,lcount-1);*/
					return ELSE;}
break;
case 52:

#line 117 "lex.l"
		return EXTERN;
break;
case 53:

#line 118 "lex.l"
			return FOR;
break;
case 54:

#line 119 "lex.l"
			return GOTO;
break;
case 55:

#line 120 "lex.l"
			{cflag=1;eatWS();return IF;}
break;
case 56:

#line 121 "lex.l"
		return REGISTER;
break;
case 57:

#line 122 "lex.l"
		return RETURN;
break;
case 58:

#line 123 "lex.l"
		return SIZEOF;
break;
case 59:

#line 124 "lex.l"
		return STATIC;
break;
case 60:

#line 125 "lex.l"
		return SWITCH;
break;
case 61:

#line 126 "lex.l"
		return TYPEDEF;
break;
case 62:

#line 127 "lex.l"
			return UNION;
break;
case 63:

#line 128 "lex.l"
		return UNSIGNED;
break;
case 64:

#line 129 "lex.l"
			{eatWS();return VOID;}
break;
case 65:

#line 130 "lex.l"
			{cflag=2;eatWS();fprintf(fc,"wlbl%d:\n",wlcount);stk1[wlbl++]=wlcount++;return WHILE;}
break;
case 66:

#line 131 "lex.l"
	eatWS();
break;
case 67:

#line 132 "lex.l"
		eatWS();
break;
case 68:

#line 133 "lex.l"
		eatWS();
break;
case 69:

#line 134 "lex.l"
			eatWS();
break;
case 70:

#line 135 "lex.l"
		{
					strcpy(str,yytext);
					eatWS();
					c=input();
					if(c=='(')
					//if(chfunction(yytext)!=0)
					{
						unput(c);
						//fexe=1;
						if(chfunction(yytext)==0)
						{
							printf("%3d\tInvalid function name: %s.\n",lineno,yytext);
							ecount++;
						}
						eatWS();
						return IDEN;
					}
					else
					{
						unput(c);
						if(dtype)
						{
							if(addToSymTab(mysymboltab((struct symboltab*)malloc(sizeof(struct symboltab)),yytext,token++,dtype,1))==-1)
							{	printf("%3d\tMultiple declarations: %s\n",lineno,yytext);
								ecount++;
							}
							if((c=input())!='=')
							fprintf(fd,"\t%s dw ?\n",yytext);
							else
							fprintf(fd,"\t%s dw",yytext);
							unput(c);
						}
						eatWS();
						strcpy(idename,yytext);	
						if(!isPresent(idename))
						{
							printf("%3d\tUndeclared Identifier: %s\n",lineno,idename);
							ecount++;
						}
						eatWS();
						return IDEN;
					}
				}
break;
case 71:

#line 178 "lex.l"
			{	printf("%3d\tInvalid identifier: %s\n",lineno,yytext);	
					ecount++;
					eatWS();
				}
break;
case -1:
break;
default:
fprintf(yyout,"bad switch yylook %d",nstr);
} return(0); }
/* end of yylex */

#line 184 "lex.l"

void eatWS()
{
	c=input();
	while(c==' '||c=='\t'||c=='\n')
	{
		if(c=='\n')
		lineno++;
		c=input();
		
	}
	unput(c);
}
void eatcom()
{
	register int c;
	lineno++;
	while(1)
	{
		while((c=input())!='*' && c!=EOF);
		{
			if(c==42)
			lineno++;
			if(c==EOF)
			{
				printf("%3d\tUnterminated Comment line: Program code in comment.\n",lineno);
				printf("Number of Errors: %d\n",ecount+1);	
				exit(1);
			}
		}
		if(c==EOF)
		{
			printf("%3d\tUnterminated Comment line: Program code in comment.\n",lineno);
			printf("Number of Errors: %d\n",ecount+1);
			exit(1);
		}
		if((c=input())=='/')
		break;
		else
		unput(c);
	}
	eatWS();
}
char * det()
{
	switch(dtype)
	{
		case 1:strcpy(str,"char");break;
		case 2:strcpy(str,"short");break;
		case 3:strcpy(str,"int");break;
		case 4:strcpy(str,"float");break;
		case 5:strcpy(str,"long");break;
		case 6:strcpy(str,"double");break;
	}
	return str;
}
void checkop()
{
	if(strcmp(yytext,"==")==0) otype=EQ;
	if(strcmp(yytext,"!=")==0) otype=NE;
	if(strcmp(yytext,">")==0)  otype=GT;
	if(strcmp(yytext,">=")==0) otype=GE;
	if(strcmp(yytext,"<")==0)  otype=LT;
	if(strcmp(yytext,"<=")==0) otype=LE;
}
int set(int no)
{
	char c;
	if(fexe)
	{
		printf("%3d\tDeclaration after Executable statement is not allowed in C.\n",lineno);
		ecount++;
		return 0;
	}
	if(dtype)
	{
		printf("%3d\tSyntax Error: %s  %s\n",lineno,det(),yytext);
		ecount++;
		while((c=input())!=';')
		{
			if(c=='\n')
			{
				printf("%3d\tMissing semicolon.\n",lineno);
				ecount++;
				return 0;
			}
		}
		return 0;
	}
	else
	return no;
}
void check(char c)
{
	if(a[--count]!=c&&count>0)
	{
		if(c=='{')
		{
			printf("%3d\tSyntax Error: Incorrect order of braces{}\n",lineno);
			ecount++;
		}
		else
		if(c=='[')
		{
			printf("%3d\tSyntax Error: Incorrect order of square brackets[]\n",lineno);
			ecount++;
		}
		else
		if(c=='(')
		{
			printf("%3d\tSyntax Error: Incorrect order of brackets()\n",lineno);
			ecount++;
		}
	}
	if(count<0)
	{
		printf("%3d\tMissing brackets.\n",lineno);
		ecount++;
	}
}
int getArguments()
{
	char c;
	int no=0,f=0;
	while((c=input())!=')');
	eatWS();
	return no;
}
int chfunction(char *fname)
{
	char sk[30][10];
	char c,tmp[50],tmp1[30],tp[30];
	int i=0,j=0,nflag=0,arg=0,ac=0;
	if(strcmp(fname,"main")==0)
	return 1;
	if(strcmp(fname,"printf")==0) //PRINTF FUNCTION
	{
		a[count++]='(';
		input();
		eatWS();
		if((c=input())=='"')
		{
			while((c=input())!='"')
			tmp[i++]=c;
			tmp[i++]='"';
			tmp[i]='\0';
		}
		eatWS();
		c=input();
		while(c==',')
		{
			i=0;
			while((c=input())!=','&&c!=')')
			tp[i++]=c;
			tp[i]='\0';
			printf("%s\n",tp);
			strcpy(sk[arg++],tp);
			if(c==')')
			break;
		}
		unput(c);
		i=0;
		while(tmp[i]!='"')
		{
			if((c=tmp[i])=='%')
			{
				if((c=tmp[i+1])=='d'||c=='c')
				/*SPECIAL PROCESSING FOR %d OR %c */
				{
					strcpy(str,"printstr");
					sprintf(str1,"%d",pcount++);
					strcat(str,str1);
					tmp1[j]='\0';
					if(strcmp(tmp1,"")!=0)
					{
						fprintf(fd,"\t%s db \"%s\",\"$\"\n",str,tmp1);
						fprintf(fc,"\tlea dx,%s\n",str);
						fprintf(fc,"\tcall print\n");
						fprintf(fc,"\tlea ax,%s\n",sk[--arg]);
						fprintf(fc,"\tcall print_num\n");
						printf("%s\n",sk[arg]);
					}
					i++;
					j=0;
					tmp1[0]='\0';
					nflag=1;
				}
			}
			if(c=='\\')
			{
				if((c=tmp[i+1])=='n')
				{
					strcpy(str,"printstr");
					sprintf(str1,"%d",pcount++);
					strcat(str,str1);
					tmp1[j]='\0';
					if(strcmp(tmp1,"")!=0)
					{
						fprintf(fd,"\t%s db \"%s\",\"$\"\n",str,tmp1);
						fprintf(fc,"\tlea dx,%s\n",str);
						fprintf(fc,"\tcall print\n");
						fprintf(fc,"\tcall newline\n");
					}
					j=0;
					tmp1[0]='\0';
					i++;
					nflag=1;
					
				}
			}
			if(!nflag)
			tmp1[j++]=c;
			else
			nflag=0;
			i++;
		}
		if(strcmp(tmp1,"")!=0)
		{
			strcpy(str,"printstr");
			sprintf(str1,"%d",pcount++);
			strcat(str,str1);
			fprintf(fd,"\t%s db \"%s\",\"$\"\n",str,tmp1);
			fprintf(fc,"\tlea dx,%s\n",str);
			fprintf(fc,"\tcall print\n");
		}
		eatWS();
		if((c=input())!=')')
		printf("%3d\tSyntax Error: ')' missing in printf call\n",lineno);
		else
		check(')');
		eatWS();
		return 1;
	}	
	return 0;
}
int yyvstop[] = {
0,

68,
0,

69,
0,

17,
0,

19,
0,

27,
0,

10,
0,

14,
0,

18,
0,

20,
0,

33,
0,

21,
0,

19,
0,

5,
8,
0,

7,
8,
0,

34,
0,

44,
0,

23,
0,

26,
0,

23,
0,

32,
0,

70,
0,

11,
0,

13,
0,

28,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

9,
0,

29,
0,

12,
0,

17,
0,

24,
0,

4,
0,

3,
0,

25,
0,

30,
0,

16,
0,

15,
0,

8,
0,

1,
0,

2,
0,

8,
0,

5,
8,
0,

8,
0,

71,
0,

71,
0,

8,
71,
0,

5,
71,
0,

71,
0,

7,
8,
0,

7,
71,
0,

22,
0,

23,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

50,
70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

55,
70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

31,
0,

3,
0,

35,
0,

8,
0,

5,
0,

8,
0,

6,
0,

6,
71,
0,

7,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

53,
70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

6,
0,

6,
71,
0,

45,
70,
0,

70,
0,

47,
70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

51,
70,
0,

70,
0,

70,
0,

54,
70,
0,

40,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

64,
70,
0,

70,
0,

46,
70,
0,

38,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

42,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

70,
0,

62,
70,
0,

70,
0,

65,
70,
0,

70,
0,

70,
0,

70,
0,

52,
70,
0,

41,
0,

70,
0,

57,
70,
0,

39,
0,

58,
70,
0,

59,
70,
0,

60,
70,
0,

70,
0,

70,
0,

70,
0,

49,
70,
0,

43,
0,

70,
0,

61,
70,
0,

70,
0,

67,
0,

48,
70,
0,

56,
70,
0,

63,
70,
0,

37,
0,

66,
0,

36,
0,
0};
# define YYTYPE int
struct yywork { YYTYPE verify, advance; } yycrank[] = {
0,0,	0,0,	1,0,	1,0,	
1,0,	1,0,	1,0,	1,0,	
1,0,	1,0,	1,3,	1,4,	
1,0,	1,0,	1,0,	1,0,	
1,0,	1,0,	1,0,	1,0,	
1,0,	1,0,	1,0,	1,0,	
1,0,	1,0,	1,0,	1,0,	
1,0,	1,0,	1,0,	1,0,	
1,0,	3,3,	1,5,	1,6,	
1,7,	1,0,	1,8,	1,9,	
1,0,	1,10,	1,11,	1,12,	
1,13,	1,14,	1,15,	1,16,	
1,17,	1,18,	1,19,	0,0,	
9,56,	0,0,	0,0,	0,0,	
3,3,	1,19,	13,57,	1,20,	
1,21,	1,22,	1,23,	1,24,	
1,25,	1,0,	1,26,	0,0,	
0,0,	0,0,	1,26,	1,26,	
1,26,	5,49,	8,55,	9,55,	
13,55,	1,26,	15,55,	15,58,	
16,59,	24,74,	16,60,	16,60,	
16,60,	16,60,	16,60,	16,60,	
16,60,	16,60,	16,60,	16,60,	
1,27,	1,0,	1,28,	1,29,	
1,0,	1,0,	1,30,	1,31,	
1,32,	1,33,	1,34,	1,35,	
1,36,	0,0,	1,37,	22,73,	
22,74,	1,38,	0,0,	0,0,	
0,0,	0,0,	0,0,	1,39,	
1,40,	1,41,	1,42,	1,43,	
1,44,	0,0,	0,0,	59,103,	
1,45,	1,46,	1,47,	1,48,	
1,0,	2,0,	2,0,	2,0,	
2,0,	2,0,	2,0,	2,0,	
2,0,	30,75,	31,76,	2,0,	
2,0,	2,0,	2,0,	2,0,	
2,0,	2,0,	2,0,	2,0,	
2,0,	2,0,	2,0,	2,0,	
2,0,	2,0,	2,0,	2,0,	
2,0,	2,0,	2,0,	2,0,	
7,53,	17,61,	36,86,	2,7,	
2,0,	7,54,	17,62,	2,0,	
2,10,	2,11,	2,12,	32,77,	
2,14,	2,15,	2,16,	2,17,	
34,82,	38,89,	32,78,	33,80,	
17,55,	35,84,	37,87,	39,90,	
35,85,	32,79,	2,20,	2,21,	
34,83,	33,81,	37,88,	2,25,	
2,0,	40,91,	40,92,	41,95,	
42,96,	43,97,	44,98,	46,55,	
50,52,	52,100,	53,101,	54,102,	
75,112,	40,93,	76,113,	77,114,	
40,94,	63,63,	63,63,	63,63,	
63,63,	63,63,	63,63,	63,63,	
63,63,	63,63,	63,63,	2,27,	
2,0,	2,28,	2,29,	2,0,	
2,0,	2,30,	2,31,	2,32,	
2,33,	2,34,	2,35,	2,36,	
6,6,	2,37,	78,115,	79,116,	
2,38,	80,117,	81,118,	82,119,	
6,6,	6,50,	2,39,	2,40,	
2,41,	2,42,	2,43,	2,44,	
83,120,	84,121,	85,122,	2,45,	
2,46,	2,47,	86,123,	2,0,	
88,124,	89,125,	90,126,	52,52,	
91,128,	92,129,	46,99,	93,130,	
6,6,	6,51,	94,131,	95,132,	
6,6,	6,6,	97,135,	90,127,	
96,133,	98,136,	6,6,	100,52,	
101,137,	102,138,	112,141,	6,6,	
6,6,	113,142,	96,134,	114,143,	
115,144,	116,145,	117,146,	6,6,	
108,105,	118,147,	119,148,	6,6,	
6,6,	6,6,	120,149,	121,150,	
6,6,	123,151,	124,152,	125,153,	
6,6,	6,6,	6,6,	126,154,	
127,155,	128,156,	129,157,	6,6,	
18,63,	130,158,	18,64,	18,64,	
18,64,	18,64,	18,64,	18,64,	
18,64,	18,64,	18,65,	18,65,	
108,105,	124,152,	131,159,	6,52,	
132,160,	133,161,	134,162,	18,66,	
18,66,	18,66,	18,66,	18,67,	
18,68,	18,66,	18,66,	18,66,	
18,66,	18,66,	18,69,	18,66,	
18,66,	18,66,	18,66,	18,66,	
18,66,	18,66,	18,66,	18,69,	
18,66,	18,66,	18,66,	18,66,	
18,66,	135,163,	136,164,	137,165,	
138,166,	6,6,	142,167,	18,66,	
18,66,	18,66,	18,66,	18,67,	
18,68,	18,66,	18,66,	18,66,	
18,66,	18,66,	18,69,	18,66,	
18,66,	18,66,	18,66,	18,66,	
18,66,	18,66,	18,66,	18,69,	
18,66,	18,66,	18,70,	18,66,	
18,66,	19,71,	19,71,	19,71,	
19,71,	19,71,	19,71,	19,71,	
19,71,	19,71,	19,71,	60,60,	
60,60,	60,60,	60,60,	60,60,	
60,60,	60,60,	60,60,	60,60,	
60,60,	145,169,	146,170,	147,171,	
149,172,	150,173,	154,175,	155,176,	
156,177,	19,72,	157,178,	158,179,	
60,104,	60,105,	159,180,	160,181,	
144,168,	65,63,	19,72,	65,65,	
65,65,	65,65,	65,65,	65,65,	
65,65,	65,65,	65,65,	65,65,	
65,65,	107,108,	107,108,	107,108,	
107,108,	107,108,	107,108,	107,108,	
107,108,	107,108,	107,108,	144,168,	
161,182,	19,72,	152,152,	153,174,	
60,104,	60,105,	162,183,	164,184,	
165,185,	166,186,	19,72,	169,187,	
170,188,	19,66,	26,26,	26,26,	
26,26,	26,26,	26,26,	26,26,	
26,26,	26,26,	26,26,	26,26,	
171,189,	152,152,	153,174,	172,190,	
175,193,	176,194,	178,196,	26,26,	
26,26,	26,26,	26,26,	26,26,	
26,26,	26,26,	26,26,	26,26,	
26,26,	26,26,	26,26,	26,26,	
26,26,	26,26,	26,26,	26,26,	
26,26,	26,26,	26,26,	26,26,	
26,26,	26,26,	26,26,	26,26,	
26,26,	179,197,	180,198,	181,199,	
183,200,	185,201,	186,202,	26,26,	
26,26,	26,26,	26,26,	26,26,	
26,26,	26,26,	26,26,	26,26,	
26,26,	26,26,	26,26,	26,26,	
26,26,	26,26,	26,26,	26,26,	
26,26,	26,26,	26,26,	26,26,	
26,26,	26,26,	26,26,	26,26,	
26,26,	62,62,	168,168,	173,191,	
187,203,	177,195,	188,204,	189,205,	
191,191,	62,62,	62,0,	192,206,	
64,63,	193,207,	64,64,	64,64,	
64,64,	64,64,	64,64,	64,64,	
64,64,	64,64,	64,65,	64,65,	
199,209,	168,168,	173,191,	174,174,	
177,195,	195,195,	189,205,	191,191,	
200,210,	62,62,	62,62,	64,104,	
64,105,	62,62,	62,62,	202,212,	
203,213,	205,205,	64,106,	62,62,	
206,214,	207,215,	208,216,	210,217,	
62,62,	62,62,	174,174,	64,106,	
195,195,	212,218,	214,219,	216,220,	
62,62,	220,222,	0,0,	0,0,	
62,62,	62,62,	62,62,	0,0,	
205,205,	62,62,	0,0,	64,104,	
64,105,	62,62,	62,62,	62,62,	
0,0,	0,0,	64,106,	0,0,	
62,62,	214,219,	0,0,	67,107,	
220,222,	67,107,	0,0,	64,106,	
67,108,	67,108,	67,108,	67,108,	
67,108,	67,108,	67,108,	67,108,	
67,108,	67,108,	0,0,	66,66,	
66,66,	66,66,	66,66,	66,66,	
66,66,	66,66,	66,66,	66,66,	
66,66,	66,66,	66,66,	66,66,	
66,66,	66,66,	66,66,	66,66,	
66,66,	66,66,	66,66,	66,66,	
66,66,	66,66,	66,66,	66,66,	
66,66,	0,0,	0,0,	174,192,	
0,0,	195,208,	62,62,	66,66,	
66,66,	66,66,	66,66,	66,66,	
66,66,	66,66,	66,66,	66,66,	
66,66,	66,66,	66,66,	66,66,	
66,66,	66,66,	66,66,	66,66,	
66,66,	66,66,	66,66,	66,66,	
66,66,	66,66,	66,66,	66,66,	
66,66,	70,109,	70,109,	70,109,	
70,109,	70,109,	70,109,	70,109,	
70,109,	70,109,	70,109,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	70,110,	70,110,	
70,110,	70,110,	70,110,	70,110,	
0,0,	0,0,	0,0,	0,0,	
71,71,	71,71,	71,71,	71,71,	
71,71,	71,71,	71,71,	71,71,	
71,71,	71,71,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	70,110,	70,110,	
70,110,	70,110,	70,110,	70,110,	
71,111,	0,0,	0,0,	0,0,	
0,0,	104,107,	0,0,	104,107,	
0,0,	71,111,	104,108,	104,108,	
104,108,	104,108,	104,108,	104,108,	
104,108,	104,108,	104,108,	104,108,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
71,111,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	71,111,	109,109,	109,109,	
109,109,	109,109,	109,109,	109,109,	
109,109,	109,109,	109,109,	109,109,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	109,109,	
109,109,	109,109,	109,109,	109,109,	
109,109,	0,0,	0,0,	0,0,	
0,0,	0,0,	109,139,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	109,139,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	109,109,	
109,109,	109,109,	109,109,	109,109,	
109,109,	0,0,	0,0,	0,0,	
0,0,	0,0,	109,139,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	109,139,	
110,109,	110,109,	110,109,	110,109,	
110,109,	110,109,	110,109,	110,109,	
110,109,	110,109,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	110,110,	110,110,	110,110,	
110,110,	110,110,	110,110,	0,0,	
0,0,	201,211,	0,0,	0,0,	
110,140,	0,0,	0,0,	0,0,	
0,0,	201,211,	201,0,	0,0,	
0,0,	110,140,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	110,110,	110,110,	110,110,	
110,110,	110,110,	110,110,	218,218,	
0,0,	201,211,	201,211,	0,0,	
110,140,	201,211,	201,211,	218,218,	
218,218,	0,0,	0,0,	201,211,	
0,0,	110,140,	0,0,	0,0,	
201,211,	201,211,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
201,211,	0,0,	0,0,	0,0,	
201,211,	201,211,	201,211,	218,218,	
218,218,	201,211,	0,0,	218,218,	
218,218,	201,211,	201,211,	201,211,	
0,0,	218,218,	0,0,	0,0,	
201,211,	0,0,	218,218,	218,218,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	218,218,	0,0,	
0,0,	0,0,	218,218,	218,218,	
218,221,	0,0,	0,0,	218,218,	
0,0,	0,0,	0,0,	218,218,	
218,218,	218,218,	0,0,	0,0,	
0,0,	0,0,	218,218,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	201,211,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
218,218,	0,0,	0,0,	0,0,	
0,0};
struct yysvf yysvec[] = {
0,	0,	0,
-1,	0,		0,	
-128,	yysvec+1,	0,	
24,	0,		yyvstop+1,
0,	0,		yyvstop+3,
12,	0,		yyvstop+5,
-231,	0,		0,	
60,	0,		0,	
13,	0,		yyvstop+7,
14,	0,		yyvstop+9,
0,	0,		yyvstop+11,
0,	0,		yyvstop+13,
0,	yysvec+8,	yyvstop+15,
15,	0,		yyvstop+17,
0,	0,		yyvstop+19,
17,	0,		yyvstop+21,
34,	0,		0,	
119,	0,		yyvstop+23,
262,	0,		yyvstop+25,
337,	yysvec+18,	yyvstop+28,
0,	0,		yyvstop+31,
0,	0,		yyvstop+33,
47,	0,		yyvstop+35,
0,	yysvec+5,	yyvstop+37,
20,	0,		yyvstop+39,
0,	0,		yyvstop+41,
410,	0,		yyvstop+43,
0,	0,		yyvstop+45,
0,	0,		yyvstop+47,
0,	yysvec+8,	yyvstop+49,
20,	yysvec+26,	yyvstop+51,
24,	yysvec+26,	yyvstop+53,
74,	yysvec+26,	yyvstop+55,
78,	yysvec+26,	yyvstop+57,
68,	yysvec+26,	yyvstop+59,
73,	yysvec+26,	yyvstop+61,
51,	yysvec+26,	yyvstop+63,
80,	yysvec+26,	yyvstop+65,
66,	yysvec+26,	yyvstop+67,
82,	yysvec+26,	yyvstop+69,
89,	yysvec+26,	yyvstop+71,
74,	yysvec+26,	yyvstop+73,
86,	yysvec+26,	yyvstop+75,
86,	yysvec+26,	yyvstop+77,
94,	yysvec+26,	yyvstop+79,
0,	0,		yyvstop+81,
138,	0,		yyvstop+83,
0,	0,		yyvstop+85,
0,	0,		yyvstop+87,
0,	0,		yyvstop+89,
-108,	yysvec+6,	yyvstop+91,
0,	0,		yyvstop+93,
-167,	yysvec+6,	0,	
101,	0,		0,	
93,	0,		0,	
0,	0,		yyvstop+95,
0,	0,		yyvstop+97,
0,	0,		yyvstop+99,
0,	0,		yyvstop+101,
77,	0,		0,	
347,	0,		yyvstop+103,
0,	0,		yyvstop+105,
-532,	0,		yyvstop+107,
161,	yysvec+60,	yyvstop+109,
498,	0,		yyvstop+111,
375,	yysvec+60,	yyvstop+114,
562,	0,		yyvstop+116,
568,	yysvec+66,	yyvstop+118,
0,	yysvec+66,	yyvstop+120,
0,	yysvec+66,	yyvstop+123,
637,	yysvec+66,	yyvstop+126,
664,	yysvec+64,	yyvstop+128,
0,	yysvec+66,	yyvstop+131,
0,	0,		yyvstop+134,
0,	0,		yyvstop+136,
88,	yysvec+26,	yyvstop+138,
105,	yysvec+26,	yyvstop+140,
92,	yysvec+26,	yyvstop+142,
137,	yysvec+26,	yyvstop+144,
125,	yysvec+26,	yyvstop+146,
135,	yysvec+26,	yyvstop+148,
121,	yysvec+26,	yyvstop+150,
124,	yysvec+26,	yyvstop+153,
132,	yysvec+26,	yyvstop+155,
138,	yysvec+26,	yyvstop+157,
136,	yysvec+26,	yyvstop+159,
138,	yysvec+26,	yyvstop+161,
0,	yysvec+26,	yyvstop+163,
140,	yysvec+26,	yyvstop+166,
147,	yysvec+26,	yyvstop+168,
155,	yysvec+26,	yyvstop+170,
149,	yysvec+26,	yyvstop+172,
139,	yysvec+26,	yyvstop+174,
166,	yysvec+26,	yyvstop+176,
161,	yysvec+26,	yyvstop+178,
155,	yysvec+26,	yyvstop+180,
167,	yysvec+26,	yyvstop+182,
165,	yysvec+26,	yyvstop+184,
168,	yysvec+26,	yyvstop+186,
0,	0,		yyvstop+188,
-183,	yysvec+6,	yyvstop+190,
174,	0,		0,	
178,	0,		0,	
0,	0,		yyvstop+192,
702,	0,		0,	
0,	0,		yyvstop+194,
0,	0,		yyvstop+196,
385,	0,		0,	
218,	yysvec+107,	yyvstop+198,
734,	0,		yyvstop+200,
804,	yysvec+66,	yyvstop+202,
0,	0,		yyvstop+205,
167,	yysvec+26,	yyvstop+207,
184,	yysvec+26,	yyvstop+209,
182,	yysvec+26,	yyvstop+211,
170,	yysvec+26,	yyvstop+213,
169,	yysvec+26,	yyvstop+215,
189,	yysvec+26,	yyvstop+217,
191,	yysvec+26,	yyvstop+219,
189,	yysvec+26,	yyvstop+221,
193,	yysvec+26,	yyvstop+223,
198,	yysvec+26,	yyvstop+225,
0,	yysvec+26,	yyvstop+227,
186,	yysvec+26,	yyvstop+230,
289,	yysvec+26,	yyvstop+232,
196,	yysvec+26,	yyvstop+234,
198,	yysvec+26,	yyvstop+236,
187,	yysvec+26,	yyvstop+238,
191,	yysvec+26,	yyvstop+240,
205,	yysvec+26,	yyvstop+242,
193,	yysvec+26,	yyvstop+244,
206,	yysvec+26,	yyvstop+246,
223,	yysvec+26,	yyvstop+248,
214,	yysvec+26,	yyvstop+250,
221,	yysvec+26,	yyvstop+252,
253,	yysvec+26,	yyvstop+254,
246,	yysvec+26,	yyvstop+256,
250,	0,		0,	
248,	0,		0,	
0,	0,		yyvstop+258,
0,	yysvec+66,	yyvstop+260,
0,	yysvec+26,	yyvstop+263,
251,	yysvec+26,	yyvstop+266,
0,	yysvec+26,	yyvstop+268,
411,	yysvec+26,	yyvstop+271,
300,	yysvec+26,	yyvstop+273,
289,	yysvec+26,	yyvstop+275,
299,	yysvec+26,	yyvstop+277,
0,	yysvec+26,	yyvstop+279,
294,	yysvec+26,	yyvstop+282,
293,	yysvec+26,	yyvstop+284,
0,	yysvec+26,	yyvstop+286,
437,	0,		yyvstop+289,
438,	yysvec+26,	yyvstop+291,
295,	yysvec+26,	yyvstop+293,
297,	yysvec+26,	yyvstop+295,
296,	yysvec+26,	yyvstop+297,
303,	yysvec+26,	yyvstop+299,
310,	yysvec+26,	yyvstop+301,
319,	yysvec+26,	yyvstop+303,
319,	yysvec+26,	yyvstop+305,
334,	yysvec+26,	yyvstop+307,
347,	yysvec+26,	yyvstop+309,
0,	yysvec+26,	yyvstop+311,
350,	yysvec+26,	yyvstop+314,
342,	0,		0,	
336,	0,		0,	
0,	yysvec+26,	yyvstop+316,
525,	0,		yyvstop+319,
345,	yysvec+26,	yyvstop+321,
348,	yysvec+26,	yyvstop+323,
367,	yysvec+26,	yyvstop+325,
361,	yysvec+26,	yyvstop+327,
526,	yysvec+26,	yyvstop+329,
550,	0,		yyvstop+331,
356,	yysvec+26,	yyvstop+333,
363,	yysvec+26,	yyvstop+335,
528,	yysvec+26,	yyvstop+337,
372,	yysvec+26,	yyvstop+339,
402,	yysvec+26,	yyvstop+341,
398,	yysvec+26,	yyvstop+343,
402,	yysvec+26,	yyvstop+345,
0,	yysvec+26,	yyvstop+347,
394,	yysvec+26,	yyvstop+350,
0,	yysvec+26,	yyvstop+352,
404,	0,		0,	
406,	0,		0,	
419,	yysvec+26,	yyvstop+355,
422,	yysvec+26,	yyvstop+357,
530,	yysvec+26,	yyvstop+359,
0,	yysvec+26,	yyvstop+361,
531,	0,		yyvstop+364,
433,	0,		0,	
444,	yysvec+26,	yyvstop+366,
0,	yysvec+26,	yyvstop+368,
552,	0,		yyvstop+371,
0,	yysvec+26,	yyvstop+373,
0,	yysvec+26,	yyvstop+376,
0,	yysvec+26,	yyvstop+379,
454,	yysvec+26,	yyvstop+382,
463,	yysvec+26,	yyvstop+384,
-876,	0,		0,	
470,	0,		0,	
471,	yysvec+26,	yyvstop+386,
0,	yysvec+26,	yyvstop+388,
564,	0,		yyvstop+391,
460,	0,		0,	
463,	yysvec+26,	yyvstop+393,
468,	0,		0,	
0,	yysvec+26,	yyvstop+395,
479,	yysvec+26,	yyvstop+398,
0,	0,		yyvstop+400,
525,	0,		0,	
0,	yysvec+26,	yyvstop+402,
577,	0,		0,	
0,	yysvec+26,	yyvstop+405,
471,	0,		0,	
0,	yysvec+26,	yyvstop+408,
-906,	0,		0,	
0,	yysvec+214,	yyvstop+411,
580,	0,		0,	
0,	0,		yyvstop+413,
0,	yysvec+220,	yyvstop+415,
0,	0,	0};
#define yytop 1032
struct yysvf *yybgin = yysvec+1;
char yymatch[] = {
00  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,011 ,012 ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
011 ,'!' ,'"' ,01  ,01  ,'%' ,'&' ,01  ,
01  ,01  ,'&' ,'+' ,01  ,'+' ,01  ,'%' ,
'0' ,'1' ,'1' ,'1' ,'1' ,'1' ,'1' ,'1' ,
'8' ,'8' ,01  ,01  ,'<' ,'=' ,'>' ,01  ,
01  ,'A' ,'A' ,'A' ,'A' ,'E' ,'F' ,'G' ,
'G' ,'G' ,'G' ,'G' ,'L' ,'G' ,'G' ,'G' ,
'G' ,'G' ,'G' ,'G' ,'G' ,'L' ,'G' ,'G' ,
'G' ,'G' ,'G' ,01  ,01  ,01  ,'&' ,01  ,
01  ,'A' ,'A' ,'A' ,'A' ,'E' ,'F' ,'G' ,
'G' ,'G' ,'G' ,'G' ,'L' ,'G' ,'G' ,'G' ,
'G' ,'G' ,'G' ,'G' ,'G' ,'L' ,'G' ,'G' ,
'G' ,'G' ,'G' ,01  ,'&' ,01  ,'~' ,01  ,
0};
char yyextra[] = {
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0};
int yylineno =1;
# define YYU(x) x
# define NLSTATE yyprevious=YYNEWLINE
char yytext[YYLMAX];
struct yysvf *yylstate [YYLMAX], **yylsp, **yyolsp;
char yysbuf[YYLMAX];
char *yysptr = yysbuf;
int *yyfnd;
int yyprevious = YYNEWLINE;
yylook()
{
	register struct yysvf *yystate, **lsp;
	register int yyt;
	register struct yywork *yyk;
	struct yysvf *yyz;
	int yych;
	int yyr;
# ifdef LEXDEBUG
	int debug;
# endif
	char *yylastch;
	/* start off machines */
# ifdef LEXDEBUG
	debug = 0;
# endif
	if (!yymorfg)
		yylastch = yytext;
	else {
		yymorfg=0;
		yylastch = yytext+yyleng;
	}
	for(;;)
	{
		lsp = yylstate;
		yyestate = yystate = yybgin;
		if (yyprevious==YYNEWLINE) yystate++;
		for (;;)
		{
# ifdef LEXDEBUG
			if(debug)fprintf(yyout,"state %d\n",yystate-yysvec-1);
# endif
			yyt = yystate->yystoff;
			if(yyt == 0)	/* may not be any transitions */
			{
				yyz = yystate->yyother;
				if(yyz == 0)break;
				if(yyz->yystoff == 0)break;
			}
			*yylastch++ = yych = input();
		tryagain:
# ifdef LEXDEBUG
			if(debug)
			{
				fprintf(yyout,"char ");
				allprint(yych);
				putchar('\n');
			}
# endif
			yyr = yyt;
			if ( yyt > 0)
			{
				yyt = yyr + yych;
				yyk = yycrank + yyt;
				if (yyt <= yytop && yyk->verify+yysvec == yystate)
				{
					if(yyk->advance+yysvec == YYLERR) /* error transitions */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyk->advance+yysvec;
					goto contin;
				}
			}
# ifdef YYOPTIM
			else if(yyt < 0) {		/* r < yycrank */
				yyt = yyr = -yyt;
# ifdef LEXDEBUG
				if(debug)fprintf(yyout,"compressed state\n");
# endif
				yyt = yyt + yych;
				yyk = yycrank + yyt;
				if(yyt <= yytop && yyk->verify+yysvec == yystate)
				{
					if(yyk->advance+yysvec == YYLERR)	/* error transitions */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyk->advance+yysvec;
					goto contin;
				}
				yyt = yyr + YYU(yymatch[yych]);
				yyk = yycrank + yyt;
# ifdef LEXDEBUG
				if(debug)
				{
					fprintf(yyout,"try fall back character ");
					allprint(YYU(yymatch[yych]));
					putchar('\n');
				}
# endif
				if(yyt <= yytop && yyk->verify+yysvec == yystate){
					if(yyk->advance+yysvec == YYLERR)	/* error transition */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyk->advance+yysvec;
					goto contin;
				}
			}
			if ((yystate = yystate->yyother) && (yyt= yystate->yystoff) != 0)
			{
# ifdef LEXDEBUG
				if(debug)fprintf(yyout,"fall back to state %d\n",yystate-yysvec-1);
# endif
				goto tryagain;
			}
# endif
			else
				{unput(*--yylastch);break;}
		contin:
# ifdef LEXDEBUG
			if(debug)
			{
				fprintf(yyout,"state %d char ",yystate-yysvec-1);
				allprint(yych);
				putchar('\n');
			}
# endif
			;
		}
# ifdef LEXDEBUG
		if(debug){
			fprintf(yyout,"stopped at %d with ",*(lsp-1)-yysvec-1);
			allprint(yych);
			putchar('\n');
			}
# endif
		while (lsp-- > yylstate){
			*yylastch-- = 0;
			if (*lsp != 0 && (yyfnd= (*lsp)->yystops) && *yyfnd > 0){
				yyolsp = lsp;
				if(yyextra[*yyfnd]){		/* must backup */
					while(yyback((*lsp)->yystops,-*yyfnd) != 1 && lsp > yylstate){
						lsp--;
						unput(*yylastch--);
						}
					}
				yyprevious = YYU(*yylastch);
				yylsp = lsp;
				yyleng = yylastch-yytext+1;
				yytext[yyleng] = 0;
# ifdef LEXDEBUG
				if(debug){
					fprintf(yyout,"\nmatch ");
					sprint(yytext);
					fprintf(yyout," action %d\n",*yyfnd);
					}
# endif
				return(*yyfnd++);
				}
			unput(*yylastch);
			}
		if (yytext[0] == 0  /* && feof(yyin) */)
			{
			yysptr=yysbuf;
			return(0);
			}
		yyprevious = yytext[0] = input();
		if (yyprevious>0)
			output(yyprevious);
		yylastch=yytext;
# ifdef LEXDEBUG
		if(debug)putchar('\n');
# endif
		}
	}

int yyback(int *p, int m)
{
	if (p==0) return(0);
	while (*p)
	{
		if (*p++ == m)
			return(1);
	}
	return(0);
}

/* the following are only used in the lex library */

int yyinput()
{
	return(input());
}
void yyoutput(int c)
{
	output(c);
}
 void

yyunput(int c)
{
	unput(c);
}
