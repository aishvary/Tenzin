#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX 211
	struct symboltab
	{
		int key;
		char name[10];
		int tok;
		int datatype;
		int scope;
		struct symboltab *next,*prev;
	}*ar[MAX]={NULL};
	struct symboltab* mysymboltab (struct symboltab *pt,char *dname,int dtok,int ddt,int dscope)
	{
		strcpy(pt->name,dname);
		pt->tok=dtok;
		pt->datatype=ddt;
		pt->scope=dscope;
		pt->next=pt->prev=NULL;
		return pt;
	}
	int getHashValue(char* s)
	{
		char *p;
		int h=0,g;
		for(p=s;(*p)!='\0';p++)
		{
			h=(h<<4)+(*p);
			if(g=h&0xf0000000)
			{
				h=h^(g>>24);
				h=h^g;
			}
		}
		return h;
	}
	void print(struct symboltab *sh)
	{
		printf("HTEntry: %s\t%d\t%d\t%d\t%d\n",sh->name,sh->key,sh->tok,sh->datatype,sh->scope);
	}
	int isPresent(char *ch)
	{
		int key;
		struct symboltab *trav;
		key=getHashValue(ch);
		if(ar[key%MAX]==NULL)
		return 0;	//Not present
		trav=ar[key%MAX];
		while(trav->key!=key)
		{
			trav=trav->next;
			if(trav==NULL)
			break;
		}
		if(trav==NULL)
		return 0;	//Not present
		else
		{
	//		print(trav);		
			return 1; 	//Present
		}
	}
	int addToSymTab(struct symboltab *add)
	{
		int key=getHashValue(add->name);
		struct symboltab *trav;
		if(isPresent(add->name))
		{
	//		printf("Entry already in Symbol Table.\n");
			return -1;
		}
		add->key=key;
		key=key%MAX;
		if(ar[key]==NULL)
		ar[key]=add;
		else
		{
			trav=ar[key];
			while(trav->next!=NULL)
			trav=trav->next;
			trav->next=add;
			add->prev=trav;
		}
	//	print(add);
		return key;	
	}
	struct symboltab* getFromSymTab(char *s)
	{
		int key=getHashValue(s);
		struct symboltab *trav=ar[key%MAX];
		if(ar[key%MAX]==NULL)
		{
			printf("Error condition.\n");
			return NULL;
		}
		while(trav->key!=key && trav!=NULL)
		trav=trav->next;
		if(trav!=NULL)
		{
	//		print(trav);
			return trav;
		}
		else
		{
			printf("Error condition.\n");
			return NULL;
		}
	}
/*	int main()
	{
		int key;
		struct symboltab *next;
		next=(struct symboltab*)malloc(sizeof(struct symboltab));
		printf("Add to Symbol Table:\n");
		mysymboltab(next,"Test",100,0,0);
		key=addToSymTab(next);
		printf("Key: %d\n",key);
		printf("Value from Symbol Table:\n");
		getFromSymTab("Test");
/*		printf("Add to Symbol Table:\n");
		mysymboltab(next,"Test",100,3,0);	
		addToSymTab(next);
		printf("\n");
		mysymboltab(next,"Test1",100,3,0);
		addToSymTab(next);
		return 0;
	}*/
	
	
