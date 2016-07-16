#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
#define YYPREFIX "yy"
#line 2 "yacc.y"
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
#line 27 "y.tab.c"
#define CHAR 257
#define SHORT 258
#define INT 259
#define FLOAT 260
#define LONG 261
#define DOUBLE 262
#define IDEN 263
#define ICON 264
#define SEMI 265
#define NOP 266
#define LC 267
#define RC 268
#define LP 269
#define RP 270
#define COMMA 271
#define EQUAL 272
#define IF 273
#define ELSE 274
#define VOID 275
#define WHILE 276
#define RELOP 277
#define EQUOP 278
#define FCON 279
#define UNOP 280
#define QUEST 281
#define ELLIPSIS 282
#define COLON 283
#define OR 284
#define AND 285
#define OROR 286
#define ANDAND 287
#define PLUS 288
#define MINUS 289
#define STAR 290
#define DIVOP 291
#define UMINUS 292
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    1,    1,    1,    1,    3,    5,    5,    4,
    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
    4,    4,    6,    6,    6,    6,    6,    6,    6,    7,
    9,    9,    9,    9,    9,    9,   10,   10,   10,   10,
    8,    8,    8,   11,   11,   11,   11,   11,   12,   12,
   12,   13,   14,   15,   15,   15,   16,   16,   16,   17,
   17,   17,   17,    2,
};
short yylen[] = {                                         2,
    7,    7,    1,    1,    1,    0,    2,    2,    0,    3,
    1,    5,    7,    5,    3,    2,    2,    4,    4,    4,
    4,    2,    1,    1,    1,    1,    1,    1,    2,    2,
    3,    4,    4,    1,    2,    2,    3,    2,    0,    2,
    3,    1,    0,    3,    3,    3,    3,    1,    3,    3,
    1,    1,    1,    3,    3,    1,    3,    3,    1,    3,
    2,    1,    1,    1,
};
short yydefred[] = {                                      0,
    5,    4,    3,    0,    0,   64,    0,    0,    0,    0,
    0,    0,    0,    0,   23,   24,   25,   26,   27,   28,
   63,   11,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   48,    0,   52,    0,    0,   59,    0,
   22,    0,   62,    0,    0,    0,    0,   61,    0,    1,
    0,    7,    0,    0,    0,    0,   16,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    2,   15,   60,
    0,    0,    0,    0,   41,    8,   36,    0,   10,    0,
    0,    0,   30,    0,    0,    0,   47,   49,    0,   50,
    0,    0,   57,   58,    0,   19,   18,    0,   31,    0,
    0,   36,    0,   38,    0,   14,   33,   32,   37,    0,
   13,
};
short yydgoto[] = {                                       4,
    5,   28,   29,   30,   52,   31,   55,   32,   82,   83,
   33,   34,   35,   36,   37,   38,   39,
};
short yysindex[] = {                                   -242,
    0,    0,    0,    0, -254,    0, -201, -249, -245, -228,
 -223,  176,  176,   16,    0,    0,    0,    0,    0,    0,
    0,    0,  176, -259, -257, -176, -259, -224, -169,  176,
 -238, -170, -213,    0, -199,    0, -208, -189,    0, -158,
    0, -139,    0, -239, -259, -126, -259,    0, -259,    0,
  176,    0,   72, -127, -119, -236,    0, -259, -259, -259,
 -259, -259, -259, -259, -259, -259, -259,    0,    0,    0,
   88, -239,  176, -107,    0,    0,    0, -261,    0,  106,
 -238, -236,    0, -221, -152, -118,    0,    0, -208,    0,
 -189, -189,    0,    0,  176,    0,    0,  176,    0,  -96,
  -93,    0, -236,    0, -102,    0,    0,    0,    0,  176,
    0,
};
short yyrindex[] = {                                   -254,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -94,    0,    0, -173,    0,  -91,
    0,    0,  109,    0,    0,    0,  220, -137,    0,    0,
    0,    0,    0,    0,  337,    0,  -94,    0,  337,    0,
  -91,    0,    0,   -1,  132,  199,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  252,    0,    0,    0,    0,    0,  316,    0,    0,
    0,  199,    0,   54,   20,  -35,    0,    0,  284,    0,
 -103,  -69,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  199,    0,  155,    0,    0,    0,    0,    0,
    0,
};
short yygindex[] = {                                      0,
    0,   -5,   29,  -28,  127,    0,    0,  -11,  -18,  -66,
   48,    0,    0,   75,  -16,   78,  -26,
};
#define YYTABLESIZE 613
short yytable[] = {                                       7,
   48,   51,   99,    6,   21,    6,   21,   44,    6,   24,
  100,   45,   56,   46,    1,  104,    2,   53,   43,   80,
   10,   43,   51,   11,    6,   54,    6,  101,   72,   27,
   70,   27,    3,   71,   81,   74,  109,   75,   12,   93,
   94,   40,   96,   13,   97,   89,   89,   49,   64,   65,
   54,   42,   43,   43,   43,   43,   43,   43,   43,   43,
   43,   43,  103,   59,   60,   61,  105,    8,    9,  106,
   58,   59,   60,   61,   41,   54,   54,   62,   63,   64,
   65,  111,   62,   62,   62,   62,   62,   62,   62,   62,
   62,   62,   47,   62,   57,   62,   62,   54,   50,   62,
   66,   67,   62,   62,   62,   84,   85,   86,   87,   68,
   62,   62,   62,   62,   62,   62,   62,   62,   56,   56,
   56,   56,   56,   56,   56,   56,   56,   56,   69,   56,
   77,   56,   56,   60,   61,   56,   88,   90,   56,   56,
   56,   91,   92,   73,   78,   79,   56,   56,   56,   56,
   56,   56,   54,   54,   54,   54,   54,   54,   54,   54,
   54,   54,   98,   54,  102,   54,   54,  107,   61,   54,
  108,  110,   54,   54,   54,   43,    9,   76,    0,    0,
   54,   54,   54,   54,   54,   54,   55,   55,   55,   55,
   55,   55,   55,   55,   55,   55,    0,   55,    0,   55,
   55,    0,    0,   55,    0,    0,   55,   55,   55,    0,
    0,    0,    0,    0,   55,   55,   55,   55,   55,   55,
   46,   46,   46,   46,   46,   46,   46,   46,   46,   46,
    0,   46,    0,   46,   46,    0,    0,   46,    0,    0,
   46,    0,    0,    0,    0,    0,    0,    0,   46,   46,
   46,    0,    0,   46,   34,   34,   34,   34,   34,   34,
   34,   34,   34,   34,    0,   34,   34,   34,    0,   34,
    0,   34,   34,    0,   34,   45,   45,   45,   45,   45,
   45,   45,   45,   45,   45,    0,   45,   34,   45,   45,
    0,    0,   45,    0,    0,   45,    0,    0,    0,    0,
    0,    0,    0,   45,   45,    0,    0,    0,   45,   44,
   44,   44,   44,   44,   44,   44,   44,   44,   44,    0,
   44,    0,   44,   44,    0,    0,   44,    0,    0,   44,
    0,    0,    0,    0,    0,    0,    0,   44,    0,    0,
    0,    0,   44,   14,   15,   16,   17,   18,   19,   20,
    6,   21,   22,    0,   23,    0,   24,   95,    0,    0,
   25,    0,    0,   26,   42,   42,   42,   42,   42,   42,
   42,   42,   42,   42,    0,   42,   27,   42,   42,    0,
    0,   42,    0,    0,   42,    0,    0,   17,   17,   17,
   17,   17,   17,   17,   17,   17,    0,   42,   17,   17,
   17,    0,    0,    0,   17,   17,    0,   17,    0,    0,
   12,   12,   12,   12,   12,   12,   12,   12,   12,   12,
   17,   12,   12,   12,    0,    0,    0,   12,    0,    0,
   12,   14,   15,   16,   17,   18,   19,   20,    6,   21,
   22,    0,   23,   12,   24,    0,    0,    0,   25,    0,
    0,   26,    0,    0,    0,   39,   39,   39,   39,   39,
   39,    0,   39,   39,   27,   39,   39,   39,    0,    0,
    0,   39,   39,    0,   39,   51,   51,   51,   51,   51,
   51,   51,   51,   51,   51,    0,   51,   39,   51,   51,
    0,    0,   51,    0,    0,   51,   53,   53,    0,    0,
    0,    0,    0,   51,   51,   51,   51,   51,   51,   51,
   51,   51,   51,   51,   51,   51,   51,    0,   51,    0,
   51,    0,    0,    0,   51,    0,    0,   51,   53,   53,
    0,    0,    0,    0,    0,   51,   51,   51,   51,   53,
   53,   53,   53,   53,   53,   53,   53,   53,   53,    0,
   53,    0,   53,   53,    0,    0,   53,    0,    0,   53,
    0,    0,    0,    0,    0,    0,    0,   53,   53,   53,
   53,   35,   35,   35,   35,   35,   35,   35,   35,    0,
   35,    0,   35,   35,   35,    0,   35,    0,   35,   35,
    0,   35,   43,   43,   43,   43,   43,   43,   43,    0,
    0,   43,    0,   43,    0,    0,   43,    0,    0,   43,
    0,    0,   43,
};
short yycheck[] = {                                       5,
   27,   30,  264,  263,  264,  263,  264,   24,  263,  269,
  272,  269,   31,   25,  257,   82,  259,  256,   24,  256,
  270,   27,   51,  269,  263,   31,  263,  289,   45,  289,
  270,  289,  275,   45,  271,   47,  103,   49,  267,   66,
   67,   13,   71,  267,   73,   62,   63,  272,  288,  289,
   56,   23,   58,   59,   60,   61,   62,   63,   64,   65,
   66,   67,   81,  285,  286,  287,   95,  269,  270,   98,
  284,  285,  286,  287,   59,   81,   82,  277,  278,  288,
  289,  110,  256,  257,  258,  259,  260,  261,  262,  263,
  264,  265,  269,  267,  265,  269,  270,  103,  268,  273,
  290,  291,  276,  277,  278,   58,   59,   60,   61,  268,
  284,  285,  286,  287,  288,  289,  290,  291,  256,  257,
  258,  259,  260,  261,  262,  263,  264,  265,  268,  267,
   59,  269,  270,  286,  287,  273,   62,   63,  276,  277,
  278,   64,   65,  270,  272,  265,  284,  285,  286,  287,
  288,  289,  256,  257,  258,  259,  260,  261,  262,  263,
  264,  265,  270,  267,   59,  269,  270,  264,  287,  273,
  264,  274,  276,  277,  278,  270,  268,   51,   -1,   -1,
  284,  285,  286,  287,  288,  289,  256,  257,  258,  259,
  260,  261,  262,  263,  264,  265,   -1,  267,   -1,  269,
  270,   -1,   -1,  273,   -1,   -1,  276,  277,  278,   -1,
   -1,   -1,   -1,   -1,  284,  285,  286,  287,  288,  289,
  256,  257,  258,  259,  260,  261,  262,  263,  264,  265,
   -1,  267,   -1,  269,  270,   -1,   -1,  273,   -1,   -1,
  276,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  284,  285,
  286,   -1,   -1,  289,  256,  257,  258,  259,  260,  261,
  262,  263,  264,  265,   -1,  267,  268,  269,   -1,  271,
   -1,  273,  274,   -1,  276,  256,  257,  258,  259,  260,
  261,  262,  263,  264,  265,   -1,  267,  289,  269,  270,
   -1,   -1,  273,   -1,   -1,  276,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  284,  285,   -1,   -1,   -1,  289,  256,
  257,  258,  259,  260,  261,  262,  263,  264,  265,   -1,
  267,   -1,  269,  270,   -1,   -1,  273,   -1,   -1,  276,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  284,   -1,   -1,
   -1,   -1,  289,  256,  257,  258,  259,  260,  261,  262,
  263,  264,  265,   -1,  267,   -1,  269,  270,   -1,   -1,
  273,   -1,   -1,  276,  256,  257,  258,  259,  260,  261,
  262,  263,  264,  265,   -1,  267,  289,  269,  270,   -1,
   -1,  273,   -1,   -1,  276,   -1,   -1,  256,  257,  258,
  259,  260,  261,  262,  263,  264,   -1,  289,  267,  268,
  269,   -1,   -1,   -1,  273,  274,   -1,  276,   -1,   -1,
  256,  257,  258,  259,  260,  261,  262,  263,  264,  265,
  289,  267,  268,  269,   -1,   -1,   -1,  273,   -1,   -1,
  276,  256,  257,  258,  259,  260,  261,  262,  263,  264,
  265,   -1,  267,  289,  269,   -1,   -1,   -1,  273,   -1,
   -1,  276,   -1,   -1,   -1,  257,  258,  259,  260,  261,
  262,   -1,  264,  265,  289,  267,  268,  269,   -1,   -1,
   -1,  273,  274,   -1,  276,  256,  257,  258,  259,  260,
  261,  262,  263,  264,  265,   -1,  267,  289,  269,  270,
   -1,   -1,  273,   -1,   -1,  276,  277,  278,   -1,   -1,
   -1,   -1,   -1,  284,  285,  286,  287,  256,  257,  258,
  259,  260,  261,  262,  263,  264,  265,   -1,  267,   -1,
  269,   -1,   -1,   -1,  273,   -1,   -1,  276,  277,  278,
   -1,   -1,   -1,   -1,   -1,  284,  285,  286,  287,  256,
  257,  258,  259,  260,  261,  262,  263,  264,  265,   -1,
  267,   -1,  269,  270,   -1,   -1,  273,   -1,   -1,  276,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  284,  285,  286,
  287,  256,  257,  258,  259,  260,  261,  262,  263,   -1,
  265,   -1,  267,  268,  269,   -1,  271,   -1,  273,  274,
   -1,  276,  256,  257,  258,  259,  260,  261,  262,   -1,
   -1,  265,   -1,  267,   -1,   -1,  270,   -1,   -1,  273,
   -1,   -1,  276,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 292
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"CHAR","SHORT","INT","FLOAT",
"LONG","DOUBLE","IDEN","ICON","SEMI","NOP","LC","RC","LP","RP","COMMA","EQUAL",
"IF","ELSE","VOID","WHILE","RELOP","EQUOP","FCON","UNOP","QUEST","ELLIPSIS",
"COLON","OR","AND","OROR","ANDAND","PLUS","MINUS","STAR","DIVOP","UMINUS",
};
char *yyrule[] = {
"$accept : st",
"st : rtype NAME LP RP LC list RC",
"st : rtype NAME RP LP LC list RC",
"rtype : VOID",
"rtype : INT",
"rtype : CHAR",
"rtype :",
"list : stmt A",
"A : stmt A",
"A :",
"stmt : Datatype VList SEMI",
"stmt : SEMI",
"stmt : IF LP expr RP stmt",
"stmt : IF LP expr RP stmt ELSE stmt",
"stmt : WHILE LP expr RP stmt",
"stmt : LC list RC",
"stmt : expr SEMI",
"stmt : Datatype VList",
"stmt : IF expr RP stmt",
"stmt : IF LP expr stmt",
"stmt : IF expr RP stmt",
"stmt : IF LP expr stmt",
"stmt : error ';'",
"Datatype : CHAR",
"Datatype : SHORT",
"Datatype : INT",
"Datatype : FLOAT",
"Datatype : LONG",
"Datatype : DOUBLE",
"Datatype : error ';'",
"VList : DecAs B",
"DecAs : NAME EQUAL ICON",
"DecAs : NAME EQUAL MINUS ICON",
"DecAs : NAME EQUAL EQUAL ICON",
"DecAs : NAME",
"DecAs : NAME EQUAL",
"DecAs : error ';'",
"B : COMMA DecAs B",
"B : DecAs B",
"B :",
"B : error ';'",
"expr : NAME EQUAL expr",
"expr : logic",
"expr :",
"logic : logic OR logic",
"logic : logic AND logic",
"logic : logic OROR logic",
"logic : logic ANDAND logic",
"logic : rel",
"rel : relA RELOP relB",
"rel : relA EQUOP relB",
"rel : bin",
"relA : relB",
"relB : bin",
"bin : bin PLUS binterm",
"bin : bin MINUS binterm",
"bin : binterm",
"binterm : binterm STAR binfact",
"binterm : binterm DIVOP binfact",
"binterm : binfact",
"binfact : LP bin RP",
"binfact : MINUS binfact",
"binfact : NAME",
"binfact : ICON",
"NAME : IDEN",
};
#endif
#ifndef YYSTYPE
typedef int YYSTYPE;
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#line 139 "yacc.y"
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

#line 570 "y.tab.c"
#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
    extern char *getenv();

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 1:
#line 33 "yacc.y"
{printf("Assembly code SUCCESSFULLY produced\n");}
break;
case 2:
#line 34 "yacc.y"
{yyerror("Incorrect order of brackets");}
break;
case 6:
#line 40 "yacc.y"
{yyerror("Main must have return type. If none then write VOID");}
break;
case 14:
#line 54 "yacc.y"
{fprintf(fc,"\tjmp wlbl%d\nlbl%d:\n",stk1[--wlbl],stk[--lbl]);}
break;
case 16:
#line 56 "yacc.y"
{if(cflag){fprintf(fc,"\tjmp lbl%d\nlbl%d:\nlbl%d:\n",lcount-1,stk[--lbl],stk[--lbl]);stk[lbl++]=lcount++;cflag=0;}}
break;
case 17:
#line 57 "yacc.y"
{yyerror("Missing ';'");}
break;
case 18:
#line 58 "yacc.y"
{yyerror("Missing '(' in IF Construct");}
break;
case 19:
#line 59 "yacc.y"
{yyerror("Missing ')' in IF Construct");}
break;
case 20:
#line 60 "yacc.y"
{yyerror("Missing '(' in IF-ELSE Construct");}
break;
case 21:
#line 61 "yacc.y"
{yyerror("Missing ')' in IF-ELSE Construct");}
break;
case 22:
#line 62 "yacc.y"
{yyerror("Expression syntax error");}
break;
case 26:
#line 68 "yacc.y"
{yyerror("FLOAT: Datatype not supported");}
break;
case 27:
#line 69 "yacc.y"
{yyerror("LONG: Datatype not supported");}
break;
case 28:
#line 70 "yacc.y"
{yyerror("DOUBLE: Datatype not supported");}
break;
case 29:
#line 71 "yacc.y"
{yyerror("Datatype error");}
break;
case 31:
#line 77 "yacc.y"
{fprintf(fd," %s\n",yytext);}
break;
case 32:
#line 79 "yacc.y"
{
			sprintf(num,"%d",65535-atoi(yytext));
			printf("%s\n",num);
			fprintf(fd," %s\n",num);}
break;
case 33:
#line 83 "yacc.y"
{yyerror("Assignment operator required");}
break;
case 35:
#line 85 "yacc.y"
{yyerror("Value with which to initialize required");}
break;
case 36:
#line 86 "yacc.y"
{yyerror("Decl Syntax Error");}
break;
case 38:
#line 90 "yacc.y"
{yyerror("Missing comma");}
break;
case 40:
#line 92 "yacc.y"
{yyerror("Declaration syntax error");}
break;
case 41:
#line 95 "yacc.y"
{gen_code(ASSIGN,pop(),pop());}
break;
case 49:
#line 107 "yacc.y"
{gen_code(CMP,pop(),pop());}
break;
case 50:
#line 108 "yacc.y"
{gen_code(CMP,pop(),pop());}
break;
case 54:
#line 118 "yacc.y"
{gen_code(ADD,pop(),pop());}
break;
case 55:
#line 119 "yacc.y"
{gen_code(SUB,pop(),pop());}
break;
case 57:
#line 123 "yacc.y"
{gen_code(MUL,pop(),pop());}
break;
case 58:
#line 124 "yacc.y"
{gen_code(DIV,pop(),pop());}
break;
case 63:
#line 131 "yacc.y"
{	sprintf(str,"iconst%d",icont++);
					push(str);
					fprintf(fd,"\t%s dw %s\n",str,yytext);
				}
break;
case 64:
#line 136 "yacc.y"
{push(yytext);}
break;
#line 841 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
