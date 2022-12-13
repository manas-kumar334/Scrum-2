#include <stdio.h>
#include <struct.h>
#include <stdlib.h>
#include <main.h>
#include <string.h>
#define ascii_value_1 48
#define ascii_value_9 57
#define ascii_value_A 65
#define ascii_value_Z 90
#define key 4
#define digit_value 10
#define digit_alphabets 26
#define buffer_length 100

void encrypt(char *ok){
	for(int i=0;i<strlen(ok);i++)
	{
        	int digit;
        	if(ok[i]>=ascii_value_1 && ok[i]<=ascii_value_9)
        	{
            	digit=ok[i]-'0';
            	digit=(digit+key)%digit_value;
                ok[i]=(char)(digit+'0');
        
        	}
        	else
        	{

		int id;
        	if(ok[i]>=ascii_value_A && ok[i]<=ascii_value_Z) 
        	{
           	 id= ok[i]-'A';
        	}
        	else
        	{
            	 id=ok[i]-'a';
       	        }
        	id = (id+key)%digit_alphabets;
        	if(ok[i]>=ascii_value_A && ok[i]<=ascii_value_Z)
        	{
            	ok[i]=(char)(id+'A');
        	}
        	else
        	{
            	ok[i]=(char)(id+'a');
        	}
		}
	}
    
}
void decrypt(char *ok){
        for(int i=0;i<strlen(ok);i++)
        {
            	int digit;
		if(ok[i]>=ascii_value_1 && ok[i]<=ascii_value_9)
		{
            	digit=ok[i]-'0';
                digit=(digit-key+digit_value)%digit_value;
                ok[i]=(char)(digit+'0');
            
        	}
        	else
        	{

        	int id;
       	        if(ok[i]>=ascii_value_A && ok[i]<=ascii_value_Z)
       	         {
                 id= ok[i]-'A';
                 }
            	else
            	{
                id=ok[i]-'a';
                }
        	id = (id-key+digit_alphabets)%digit_alphabets;
        	if(ok[i]>=ascii_value_A && ok[i]<=ascii_value_Z)
        	{
            	ok[i]=(char)(id+'A');
        	}
       	        else
       	        {
                ok[i]=(char)(id+'a');
        	}
        	}

   	 }
}


int ProductManagerRegistration(){
    /* 
    Author:Akanksha Singh
    */
	char user[buffer_length];
	printf("Enter username :\n");
	scanf("%s",user);
	char pass[buffer_length];
	printf("Enter password :\n");
	scanf("%s",pass);
	encrypt(pass);
	char role[]="productmanager";
	FILE *f=fopen("../data/login.txt","a");
	if(f==NULL)
	{
	printf("can't open file\n");
	exit(0);
	}
	else
	{
	fprintf(f,"%s,%s,%s\n",user,pass,role);
	}
	fclose(f);
    printf("Congratulations, your account has been successfully created.\n");
    main();
    return EXIT_SUCCESS;
        
}
int ProductManagerLogin(){
    /*
    Author:Santipriya Bodeboina
    */
	char user[buffer_length];
	printf("Enter username for login:\n");
	scanf("%s",user);
	char pass[buffer_length];
	printf("Enter password for login :\n");
	scanf("%s",pass);
	FILE *f=fopen("../data/login.txt","r");
	if(f==NULL)
	{
		printf("can't open file\n");
		exit(0);
	}
	else
	{
		char buf[buffer_length];
		while(fgets(buf,buffer_length,f)!=NULL)
		{
		char *u,*p,*r;
		u=strtok(buf,",");
		p=strtok(NULL,",");
		decrypt(p);
			if(strcmp(u,user)==0 && strcmp(p,pass)==0)
			{
			r=strtok(NULL,"\n");
			if(strcmp(r,"productmanager")==0)
			{
			return 1;
			}
			}
		}
	}
	fclose(f);
	printf("Incorrect credentials\n");
   	return 0;
}

int ReleaseManagerRegistration(){
    /* 
    Author:Akanksha Singh
    */
    char user[buffer_length];
	printf("Enter username :\n");
	scanf("%s",user);
	char pass[buffer_length];
	printf("Enter password :\n");
	scanf("%s",pass);
	encrypt(pass);
	char role[]="releasemanager";
	FILE *f=fopen("../data/login.txt","a");
	if(f==NULL)
	{
	printf("can't open file\n");
	exit(0);
	}
	else
	{
	fprintf(f,"%s,%s,%s\n",user,pass,role);
	}
	fclose(f);
        printf("Congratulations, your account has been successfully created.\n");
        main();
    return EXIT_SUCCESS;

}

int ReleaseManagerLogin(){
    /*
    Author: Santipriya BodeBoina
    */
	char user[buffer_length];
	printf("Enter username for login:\n");
	scanf("%s",user);
	char pass[buffer_length];
	printf("Enter password for login :\n");
	scanf("%s",pass);
	FILE *f=fopen("../data/login.txt","r");
	if(f==NULL)
	{
		printf("can't open login.txt");
		exit(0);
	}
	else
	{
		char buf[buffer_length];
		while(fgets(buf,buffer_length,f)!=NULL)
		{
		char *u,*p,*r;
		u=strtok(buf,",");
		p=strtok(NULL,",");
		decrypt(p);
			if(strcmp(u,user)==0 && strcmp(p,pass)==0)
			{
			r=strtok(NULL,"\n");
			if(strcmp(r,"releasemanager")==0)
			{
			return 1;
			}
			}
		}
	}
	fclose(f);
	printf("Incorrect credentials\n");
   	return EXIT_SUCCESS;
}
