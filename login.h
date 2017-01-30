#if !defined (LOGIN_H)
#define LOGIN_H
#include <windows.h>
#include "graphics.h"
#include <conio.h>
#include <cstdio>
#include<stdlib.h>
#include<string.h>
#include<dir.h>
#include<time.h>
char pass[20];
char newUser[60];
char pet[10];
void clear_string(char *string)
{
	string[0]='\0';
}
void trimR(char *string)
{
	int i;
	for(i=0;i<sizeof(string);i++)
	{
		string[i]=string[i+1];	
	}	
}	
void Pass(char c) //asteriks for pass
{
	
	int i=0;
	do
	{
		c=getch();
		if(isprint(c))
		{
			pass[i++]=c;
			printf("*");	
		}
		
	}while(c!=13);
}

void trim(char name[20])
{
	int	size=strlen(name);
	if(name[size-1]=='\n') //adding \0 to end
		{
			name[size-1]='\0';
		}
			
}
int checkUser(char *User, char *file) //checking user name
{
	FILE  *user=fopen(file,"r");
	char name[128];
	int size;
	if(user!=NULL)
	{
		while(fgets(name, sizeof name, user)!=NULL)	
		{
			size=strlen(name);
			trim(name);
			
			if(strcmp(name,User)==0)
			{
				return 1;
			}		
		}
		return 0;
	}
	
		
}
void getPass(char *User)
{
	int size;
	char file[50]="E:/Imps/prog/Chat/";
	strcat(file,User);
	strcat(file,"/Pass.txt");
	FILE *password=fopen(file,"r");
	char pword[10];
	if(password!=NULL)
	{
		
		fgets(pword,sizeof pword, password);
		printf("\n\t\t       Your password is : ");
		puts(pword);
	}
}

int checkPass(char *User) //checking password
{
	int size;
	char file[50]="E:/Imps/prog/Chat/";
	strcat(file,User);
	strcat(file,"/Pass.txt");
	FILE *password=fopen(file,"r");
	char pword[10];
	if(password!=NULL)
	{
		
		fgets(pword,sizeof pword, password);
		size=strlen(pword);
		trim(pword);
		if(strcmp(pword,pass)==0)
		{
			return 1;
		}
	
		
	}
	else
	{
		printf("jbgj");
	}
	return 0;
}
void newUse(char *file)
{
	FILE *user=fopen(file,"a");
	char c;
	char Add[50]="E:/Imps/prog/Chat/";
	char SAdd[50]="E:/Imps/prog/Chat/";
	//Signup
	printf("\n\n\n\t\t\t\t---------------");
	printf("\n\t\t\t\t| SIGNUP PANEL |");
	printf("\n\t\t\t\t---------------");
	printf("\n\n\n\t\t\t Username: ");
	fflush(stdin);
	gets(newUser);
	printf("\n\n\t\t\t Password: ");
	Pass(c);
	printf("\n\n\t\t  What is your pet's name: ");
	gets(pet);
	
	mkdir(newUser); //make folder
	
	fprintf(user,newUser);
	fprintf(user,"\n");
	fclose(user);
	
	strcat(Add,newUser);
	strcat(SAdd,newUser);
	strcat(Add,"/Pass.txt");//making address for password
	strcat(SAdd,"/Que.txt");//making address for Sec Question
	
	FILE *Pass=fopen(Add,"a");//for password
	fprintf(Pass, pass);
	fprintf(Pass,"\n");
	fclose(Pass);
	
	FILE *Sec=fopen(SAdd,"a");//for sec question
	fprintf(Sec, pet);
	fprintf(Sec,"\n");
	fclose(Sec);
}
int fPass(char *User)
{
	char SAdd[50]="E:/Imps/prog/Chat/";
	strcat(SAdd,User);
	strcat(SAdd,"/Que.txt");
	FILE *Sec=fopen(SAdd,"r");
	char que[10];
	printf("\n\n\n\t\t\tWhat is your pet's name: ");
	fflush(stdin);
	gets(pet);
	int size;
	if(Sec!=NULL)
	{
		
		fgets(que,sizeof que, Sec);
		size=strlen(que);
		trim(que);
		if(strcmp(que,pet)==0)
		{
			getPass(User);
			return 1;
		}
		else
		{
			settextcolor(12);
			printf("\n\n\t\t\t\t   Wrong answer");
			settextcolor(WHITE);
		}
	
		
	}
		
		return 0;
}
#endif
