#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
char prevInput[90];
char prevResp[90];
int tot;
//structures for all words
struct Tran
{
	int i;
	int size;
	char *str[20];
}Tran;
struct Rtran
{
	int i;
	int size;
	char *str[20];
}Rtran;
struct Null
{
	int i;
	int size;
	char *string[20];
}Null;

struct Nokey
{
	int i;
	int size;
	char *str[20];
}Nokey;

struct Sign
{
	int i;
	int size;
	char *str[20];
}Sign;

struct Recall
{
	int i;
	int size;
	char *str[20];
}Recall;

struct Topic_Change
{
	int i;
	int size;
	char *str[20];
}Topic_Change;

struct Repeat
{
	int i;
	int size;
	char *str[20];
}Repeat;

struct Key
{
	int i;
	int size;
	char*str[20];
}Key[150];

struct Response
{
	int i;
	int size;
	char *str[20];
}Response[150];
//trimming char like N S T etc
void trimR(char *string)
{
	int i=0;
	while(string[i]!='\0')
	{
		string[i]=string[i+1];
		i++;
	}
}	
//trimming the file string
void trim(char name[20])
{
	int	size=strlen(name);
	if(name[size-1]=='\n') //adding \0 to end
		{
			name[size-1]='\0';
		}
			
}
//saving user input
void savePrevInput(char *now, char *prev)
{
	strcpy(prev,now);
}
//checking repetition of user
int user_repeat(char* input)
{
	int static count=0;
	if(strcmp(prevInput,input)==0)
	{	
		count++;
		if(count>2)
		{
			return 1;
		}
		else
		return 0;		
	}
	else
	count=0;
	return 0;
}
int bot_repeat(char* resp)
{
	if(strcmp(prevResp,resp)==0)
	{
		return 1;
	}
	else 
		return 0;
}

//find keyword
int find_keyword(char *str)
{
	int i,j,ran;
	srand(time(NULL));
	for(i=1;i<tot;i++)
	{
		for(j=0;j<=Key[i].size;j++)
		{
			if(strstr(str,Key[i].str[j]))
			{
				do
				{
					ran=rand()%Response[i].size;
				}while(bot_repeat(Response[i].str[ran]));
				printf(">>");
				puts(Response[i].str[ran]);
				strcpy(prevResp,Response[i].str[ran]);
				return 1;
			}
		}
	}
	return 0;
}
void select_response(char res)
{
	char *response;
	int ran;
	switch(res)
	{
		case 'S':
			srand(time(NULL));
			ran=rand()%Sign.size;
    		response=Sign.str[ran];
    		printf(">> ");
    		puts(response);
			break;
		case 'M':
			printf("Recall\n");
			break;
		case 'N':
			ran=rand()%Null.size;
			response=Null.string[ran];
			printf(">> ");
			puts(response);
			break;
		case 'X':
			ran=rand()%Nokey.size;
			response=Nokey.str[ran];
			printf(">> ");
			puts(response);
			break;
			
			break;
		case 'Z':
			srand(time(NULL));
			ran=rand()%Topic_Change.size;
			response=Topic_Change.str[ran];
			printf(">> ");
			puts(response);
			break;
		case 'W':
			srand(time(NULL));
			ran=rand()%Repeat.size;
			response=Repeat.str[ran];
			printf(">> ");
			puts(response);
			break;
			
	}
}
void preProcessInput(char *str)
{
	int i,j;
	for(i=0;str[i]!='\0';i++)
	str[i]=toupper(str[i]);
	
	for(i=0;str[i]!='\0';i++)
	{
		if(ispunct(str[i]))
		{
			j=i;
	        while(str[j]!='\0')
	        {
	        	str[j]=str[j+1];
	        	j++;
		    }
		}
	}
}
/*void recall()
{
	char buffer[128];
	int i,k,w,j=0,t=0,p;
	char str[10][10];
	FILE *trans=fopen("trans.txt","r");
	char cSym;
	while(fgets(buffer, sizeof buffer, trans)!=NULL)
	{
		cSym=buffer[0];
		switch(cSym)
		{
			case'`':
				break;
		    case 'T':
		    	{
		    		trimR(buffer);
		         	trim(buffer);
	    		    Tran.str[Tran.i]=strdup(buffer);
	        		Tran.i++;
	        	}
				break;
			case 'R':
		    	{
		    		trimR(buffer);
		         	trim(buffer);
	    		    Rtran.str[Rtran.i]=strdup(buffer);
	        		Rtran.i++;
	        		break;
	        	}
				    	
		}
		
	}
	
	fclose(trans);
	
}*/
int quit(char *input)
{
	int i;
	for(i=0;i<=Key[0].size;i++)
	{
		if(strstr(input,Key[0].str[i]))
		return 1;
	}
	return 0;	
}
void respond(char *input)
{
	int ran;
	preProcessInput(input);
	if(strlen(input)==0)
	{
		select_response('N');
	} 
	else if(user_repeat(input)) 
	{
		select_response('W');
	} 
	else if(!find_keyword(input))
	{
		if(!quit(input))
		{
			srand(time(NULL));
			ran=rand()%9;
			if(ran==3||ran==6)
			{
				select_response('Z');
			}
			else
			select_response('X');
			
		}
		//recall();	
	}
	//handle_repetition();*/
}
//checking quitting

int main ( void )
{
	char cSym;
	char cPrevSym;
	int j=0,ran;
	char input[90];
	FILE *script=fopen("Script.txt","r");
	char buffer[128];
	while(fgets(buffer, sizeof buffer, script)!=NULL)
	{
		cPrevSym=cSym;
		cSym=buffer[0];
		switch(cSym)
		{
	 	case '#':
			break;
		case 'S':
    		trimR(buffer);
			Sign.str[Sign.i]=strdup(buffer);
			Sign.i++;
			break;
		case 'M':
			trimR(buffer);
			Recall.str[Recall.i]=strdup(buffer);
			Recall.i++;
			break;
		case 'N':
			trimR(buffer);
			trim(buffer);
			Null.string[Null.i]=strdup(buffer);
			Null.i++;		
			break;
		case 'X':
			trimR(buffer);
			trim(buffer);
			Nokey.str[Nokey.i]=strdup(buffer);
			Nokey.i++;
			break;
		case 'Z':
			trimR(buffer);
			trim(buffer);
			Topic_Change.str[Topic_Change.i]=strdup(buffer);
			Topic_Change.i++;
			break;
		case 'W':
			trimR(buffer);
			trim(buffer);
			Repeat.str[Repeat.i]=strdup(buffer);
			Repeat.i++;
			break;
			}
		
    }
    int count=0;
	FILE *key=fopen("key.txt","r");
	while(fgets(buffer, sizeof buffer, key)!=NULL)
	{
		cSym=buffer[0];
		switch(cSym)
		{
			case'`':
				count++;
				break;
		    case 'K':
		    	if(count<2)
		    	{
		    		trimR(buffer);
		         	trim(buffer);
	    		    Key[j].str[Key[j].i]=strdup(buffer);
	        		Key[j].i++;
	        	}
				break;
			case 'R':
				if(count<2)
		    	{
		    		trimR(buffer);
		         	trim(buffer);
	    		    Response[j].str[Response[j].i]=strdup(buffer);
	        		Response[j].i++;
	        	}
				break;    	
		}
		if(count==2)
		{
			Response[j].size=(Response[j].i);
			Key[j].size=(Key[j].i)-1;
			count=0;
			j++;
		}
	}
	tot=j;
	fclose(key);
    fclose(script);
    Null.size=Null.i-1;
    Nokey.size=Nokey.i-1;
    Recall.size=Recall.i-1;
    Repeat.size=Repeat.i-1;
    Topic_Change.size=Topic_Change.i-1;
    Sign.size=Sign.i-1;
    char response_list='S';
    select_response(response_list);
    here:
    while(!quit(input))
	{
	    printf("YOU: ");
	    savePrevInput(input,prevInput);
	    gets(input);
    	respond(input);
	}
	printf(">>");
	srand(time(NULL));
	ran=rand()%3;
	puts(Response[0].str[ran]);
	printf("YOU: ");
	gets(input);
	preProcessInput(input);
	if(strstr(input,"YES")||strstr(input,"YEAH")||strstr(input,"YUP")||strstr(input,"BYE"))
	printf(">> OK BYE!!");
	else
	{
		printf(">> THEN LET'S CONTINUE WITH THE CONVERSATION\n");
		goto here; 
	}
}

