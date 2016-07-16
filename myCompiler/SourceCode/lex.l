%{
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
%}

ID	 [A-Za-z0-9]
A	 [A-Za-z]
d	 [0-9]
h	 [0-9a-fA-F]
o	 [0-7]
suffix   [UuLl]
delim	 [ \t]

%%

"/*"				eatcom();
"//"(.)*
\"(\\.|[^\"])*\"		return STRING;
\"(\\.|[^\"])*\n		printf("Adding missing \" to sting constant");
0{o}*{suffix}?  | 
0x{h}+{suffix}? |
[1-9]{d}*{suffix}?		{strcpy(idename,yytext);return ICON;}
({d}+|{d}+\.{d}*|{d}*\.{d}+)([eE][\-+]?{d}+)?[fF]?	return FCON;

"{"				{a[count++]='{';fexe=0;eatWS();return LC;}
"("				{a[count++]='(';eatWS();return LP;}
"["				{a[count++]='[';eatWS();return LB;}
"}"				{check('{');eatWS();
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
"]"				{check('[');eatWS();return RB;}
")"				{check('(');eatWS();return RP;}
"->" | "."			return STRUCTOP;
"++" | "--"			return INCOP;
[~!]				return UNOP;
"*"				{eatWS();return STAR;}
[/%]				{eatWS();return DIVOP;}
"+"				{eatWS();return PLUS;}
"-"				{eatWS();return MINUS;}
"<<" | ">>"			return SHIFTOP;
[<>]=?				{checkop();return RELOP;}
[!=]=				{checkop();return EQUOP;}
[*/%+\-&|^]= | (<<|>>)=		return ASSIGNOP;
"="				return EQUAL;
"&"				return AND;
"^"				return XOR;
"|"				return OR;
"&&"				return ANDAND;
"||"				return OROR;
"?"				return QUEST;
","				{eatWS();return COMMA;}
":"				return COLON;
"..."				return ELLIPSIS;
short{delim}+int{delim}+	{	dtype=set(2); eatWS();
					return SHORT;	}
long{delim}+int{delim}+		{	dtype=set(5); eatWS();
					return LONG;	}
char{delim}+			{	dtype=set(1); eatWS();
					return CHAR;	}
short{delim}+			{	dtype=set(2); eatWS();
					return SHORT;	}
int{delim}+			{	dtype=set(3); eatWS();
					return INT;	}
float{delim}+			{	dtype=set(4); eatWS();
					return FLOAT;	}
long{delim}+			{	dtype=set(5); eatWS();
					return LONG;	}
double{delim}+			{	dtype=set(6); eatWS();
					return DOUBLE;	}
";"				{	dtype=0;
					eatWS();
					return SEMI;}
"auto"				return AUTO;
"break"				return BREAK;
"case"				return CASE;
"continue"			return CONTINUE;
"default"			return DEFAULT;
"do"				return DO;
"else"				{	cflag=3;
					eatWS();
				/*a	stk[lbl++]=lcount;
					fprintf(fc,"\tjmp lbl%d\nlbl%d:\n",lcount++,lcount-1);*/
					return ELSE;}
"extern"			return EXTERN;
"for"				return FOR;
"goto"				return GOTO;
"if"				{cflag=1;eatWS();return IF;}
"register"			return REGISTER;
"return"			return RETURN;
"sizeof"			return SIZEOF;
"static"			return STATIC;
"switch"			return SWITCH;
"typedef"			return TYPEDEF;
"union"				return UNION;
"unsigned"			return UNSIGNED;
"void"				{eatWS();return VOID;}
"while"				{cflag=2;eatWS();fprintf(fc,"wlbl%d:\n",wlcount);stk1[wlbl++]=wlcount++;return WHILE;}
"#include<"[^>]*">"		eatWS();/*eat include statements*/
"#define"[^\n]			eatWS();/*eat define statements*/
{delim}+			eatWS();/*EAT WHITESPACES*/
[\n]				eatWS();
{A}{ID}*			{
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
{d}{A}+				{	printf("%3d\tInvalid identifier: %s\n",lineno,yytext);	
					ecount++;
					eatWS();
				}

%%

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
