
#include <evm_operations.h>

//int votesCount1=0, votesCount2=0, votesCount3=0, votesCount4=0, spoiledtvotes=0;
void menu()
{
    int choice;
    do{
        time_t t;
	time(&t);
	printf("                                                                                                         \n");
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t%s",ctime(&t));
	printf("---------------------------------------------------------------------------------------------------------\n");

 printf("\n\n ###### Welcome to Election/Voting 2020 #####");
printf("\n\n 1. Cast the Vote");
printf("\n 2. Find Vote Count(only for admin)");
printf("\n 3. Find leading Candidate(only for admin)");
printf("\n 4. exit");

printf("\n\n Please enter your choice : ");
scanf("%d", &choice);
int a;
switch(choice)
{
case 1: castVote();break;
case 2: votesCount();break;
case 3: a=leadingCandidate(1,1);


        break;
case 4:printf("THANKYOU FOR USING EVM");getch();system("cls");main();
default: printf("\n Error: Invalid Choice!!!\n Please enter a valid Choice");getch();system("cls");
}
}while(choice!=0);

//hold the screen
getchar();

}



int main()
{   int id;
    printf("\n  ========================  BOOTH LOGIN   ========================  ");
    printf(" \n                        BOOTH ID:-");
	scanf("%d",&id);
    boothid(id);

return 0;
}
