#ifndef __EVM_OPERATIONS_H__
#define __EVM_OPERATIONS_H__

#include <stdio.h>
#include <stdlib.h>
//#include<conio.h>
#include<time.h>
#include <string.h>
#define BUFFER_SIZE 1000
#define CANDIDATE_COUNT

#define CANDIDATE1 "Dhuma M S"
#define CANDIDATE2 "R S Sravya"
#define CANDIDATE3 "Mohammed Eshaan"
#define CANDIDATE4 "Abhirami V K"

//int votesCount1=0, votesCount2=0, votesCount3=0, votesCount4=0, spoiledtvotes=0;
int boothid(int id);
int adLogin(char uname[10],char pword[10]);
void castVote(void);
int CheckVoterId(FILE *fptr, const char *word, int *line, int *col);
void votesCount(void);
int leadingCandidate(int x,int y);


#endif
