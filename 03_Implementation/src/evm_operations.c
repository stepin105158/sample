#include <evm_operations.h>
int votesCount1=0, votesCount2=0, votesCount3=0, votesCount4=0, spoiledtvotes=0;

int boothid(int id)//EVM ACTIVATION
{


     int boothid=100500;


    if(id==boothid)
	{
	    printf("#####EVM ACTIVATED######\n");
	    printf("CHIEF ELECTORAL OFFICER- Mr.Shyam Prasad Sharma\n");
	    printf("CONSTITUTION- TRIVANDRUM");
	    getch();
	    system("cls");
	     menu();
	    return 1;

	}
	else
	{
		printf("\n        SORRY !!!!  INCORRECT BOOTH ID\n          EVM ACTIVATION FAILED");



		getch();//holds the screen
		main();
		return 0;

	}
}
//TO CAST VOTE
void castVote(){
    FILE *fptr;
    FILE *fpt1;

    char word[50];

    int line, col;
    printf("Enter your voter id ");
    scanf("%s", word);


    /* Try to open file */
    fptr = fopen("VoterId.txt", "r");

    /* Exit if file not opened successfully */
    if (fptr == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check you have read/write previleges.\n");

        exit(EXIT_FAILURE);
    }


    // check the voter id
    CheckVoterId(fptr, word, &line, &col);

    if (line != -1){
        printf("YOU HAVE ALREADY VOTED");
        getch();
        system("cls");}
    else
        {
             fclose(fptr);

   fpt1= (fopen("VoterId.txt", "a"));
   if(fpt1 == NULL)
   {
       printf("Error!");
       exit(1);

   }

        fprintf(fpt1," \n %s \n",word);
int choice;
printf("\n\n ### Please choose your Candidate ####\n\n");
printf("\n 1. %s", CANDIDATE1);
printf("\n 2. %s", CANDIDATE2);
printf("\n 3. %s", CANDIDATE3);
printf("\n 4. %s", CANDIDATE4);
printf("\n 5. %s", "None of These");

printf("\n\n Input your choice (1 - 5) : ");
scanf("%d",&choice);


switch(choice){
    case 1: votesCount1++; break;
    case 2: votesCount2++; break;
    case 3: votesCount3++; break;
    case 4: votesCount4++; break;
    case 5: spoiledtvotes++; break;
    default: printf("\n Error: Wrong Choice !! Please retry");
             //hold the screen
            //getchar();
}
printf("\n THANKYOU FOR VOTING !!");

getch();

system("cls");
fclose(fpt1);


        }


    // Close file
    fclose(fptr);


menu();
}
// DISPLAY THE VOTE COUNT
void votesCount(){
    system("cls");
int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="admin";
    char pass[10]="passkey";
    do
{

    printf("\n  ========================  ADMIN LOGIN   ========================  ");
    printf(" \n                        USERNAME:-");
	scanf("%s", &uname);
	printf(" \n                        PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword);
	int y=adLogin(uname,pword);

		if(y==1)
	{printf("\n\n ##### Voting Statics ####");
printf("\n %s - %d ", CANDIDATE1, votesCount1);
printf("\n %s - %d ", CANDIDATE2, votesCount2);
printf("\n %s - %d ", CANDIDATE3, votesCount3);
printf("\n %s - %d ", CANDIDATE4, votesCount4);
printf("\n %s - %d ", "Spoiled Votes", spoiledtvotes);
getch();
system("cls");
 menu();
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;


		getch();//holds the screen


	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for three times!!!");

		getch();

		}
		system("cls");

}


//TO CHECK THE VOTER ID IS UNIQUE
int CheckVoterId(FILE *fptr, const char *word, int *line, int *col)//checks if the voter Id is new
{
    char str[BUFFER_SIZE];
    char *pos;

    *line = -1;
    *col  = -1;

    while ((fgets(str, BUFFER_SIZE, fptr)) != NULL)
    {
        *line += 1;

       // Find first occurrence of word in str
        pos = strstr(str, word);

        if (pos != NULL)
        {
            // First index of word in str is
            // Memory address of pos - memory
            // address of str.
            *col = (pos - str);
            break;
        }
    }


    // If word is not found then set line to -1
    if (*col == -1)
        *line = -1;

    return *col;
}

//ADMIN LOGIN
int adLogin(char uname[10],char pword[10])
{
 if(strcmp(uname,"admin")==0 && strcmp(pword,"passkey")==0)
 {
     return 1;
 }
 else
    return 0;
}
// TO FIND THE LEADING CANDIDATE
int leadingCandidate(int x,int y){
    system("cls");
    int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="admin";
    char pass[10]="passkey";
    do
{

    printf("\n  ========================  ADMIN LOGIN   ========================  ");
    printf(" \n                        USERNAME:-");
	scanf("%s", &uname);
	printf(" \n                        PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword);
	int p=adLogin(uname,pword);

		if(p==1)
	{
	     printf("\n\n  #### Leading Candiate ####\n\n");
     if(votesCount1>votesCount2 && votesCount1>votesCount3 && votesCount1 >votesCount4)
    {printf("\t%s",CANDIDATE1);
    getch();
    system("cls");
    menu();return 3;
    }
    else if (votesCount2>votesCount3 && votesCount2>votesCount4 && votesCount2 >votesCount1)
    {printf("\t%s",CANDIDATE2);return 4;
    getch();
    system("cls");
    menu();}
    else if(votesCount3>votesCount4 && votesCount3>votesCount2 && votesCount3 >votesCount1)
    {printf("\t%s",CANDIDATE3);return 5;
    getch();
    system("cls");
    menu();}
    else if(votesCount4>votesCount1 && votesCount4>votesCount2 && votesCount4 >votesCount3)
    {printf("\t%s",CANDIDATE4);return 6;
    getch();
    system("cls");
    menu();}
    else
    {printf("----- Warning !!! No-win situation----");}
    getch();
    system("cls");
    menu();
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();//holds the screen

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for three times!!!");

		getch();

		}
		system("cls");

   }
