#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



#define RESET		0
#define BRIGHT 		1

#define BLACK 		-2
#define RED		    1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define	WHITE		7

int row,col,number,foreclr;
int i,j,k,m,l,dots;

void textcolor(int attr,int fg);
void printDate();
void printTime(char *clr);
void PrintFigureColor();
int ChooseClr(char *WhatColor);
void Datecolor(int attr, int fg);
void printAll(char *color);



char *clr[8]={"black","red","green","yellow","blue","magenta","cyan","white"};


int main(int argc, char **argv) {

if((argc==1)){

	printAll(clr[7]);
}
 if(argc==2){
    if(strcmp(argv[1],"-C")!=1){
        printf("%s: option requires an argument -- '%s'\n",argv[0],argv[1]);
        printf("usage : clock -C <black|red|green|yellow|blue|magenta|cyan|white]\n");
    }
 }
if(argc==3){
   if(strcmp(argv[1],"-C")==0){
    printAll(argv[2]);
   }
   else{
    printf("KFkj");
   }

}

return 0;
}

void printDate(){
char buff[100];
time_t now=time(0);
strftime(buff,100,"%Y-%m-%d", localtime(&now));

    printf("\n");
    printf("\t\t      ");
    Datecolor(RESET,foreclr);
	printf("%s\n",buff);
	Datecolor(RESET,BLACK);
}


void PrintFigureColor(){

    textcolor(BRIGHT,foreclr);
    printf(" ");
    textcolor(RESET,BLACK);

}


int ChooseClr(char *WhatColor){

    int j,Assign;

    for( j=0;j<8;j++){


        if(strcmp(WhatColor,clr[j])==0){
                Assign=j;
        }

    }

    return Assign;
}


void textcolor(int attr, int fg)
{	char command[13];

	sprintf(command, "%c[%d;%dm", 0x1B, attr, fg + 40);
	printf("%s", command);
}

void Datecolor(int attr, int fg)
{	char command[13];

	sprintf(command, "%c[%d;%dm", 0x1B, attr, fg + 30);
	printf("%s", command);
}




void printTime(char *clr){

int Number[10][5][6] ={

                      { { 1,1,1,1,1,1 },
                        { 1,1,0,0,1,1 },
                        { 1,1,0,0,1,1 },
                        { 1,1,0,0,1,1 },
                        { 1,1,1,1,1,1 }  },

                      { { 0,0,0,0,1,1 },
                        { 0,0,0,0,1,1 },
                        { 0,0,0,0,1,1 },
                        { 0,0,0,0,1,1 },
                        { 0,0,0,0,1,1 }  },

                      { { 1,1,1,1,1,1 },
                        { 0,0,0,0,1,1 },
                        { 1,1,1,1,1,1 },
                        { 1,1,0,0,0,0 },
                        { 1,1,1,1,1,1 }  },

                      { { 1,1,1,1,1,1 },
                        { 0,0,0,0,1,1 },
                        { 1,1,1,1,1,1 },
                        { 0,0,0,0,1,1 },
                        { 1,1,1,1,1,1 }  },

                      { { 1,1,0,0,1,1 },
                        { 1,1,0,0,1,1 },
                        { 1,1,1,1,1,1 },
                        { 0,0,0,0,1,1 },
                        { 0,0,0,0,1,1 }  },

                      { { 1,1,1,1,1,1 },
                        { 1,1,0,0,0,0 },
                        { 1,1,1,1,1,1 },
                        { 0,0,0,0,1,1 },
                        { 1,1,1,1,1,1 }  },

                      { { 1,1,1,1,1,1 },
                        { 1,1,0,0,0,0 },
                        { 1,1,1,1,1,1 },
                        { 1,1,0,0,1,1 },
                        { 1,1,1,1,1,1 }  },

                      { { 1,1,1,1,1,1 },
                        { 0,0,0,0,1,1 },
                        { 0,0,0,0,1,1 },
                        { 0,0,0,0,1,1 },
                        { 0,0,0,0,1,1 }  },

                      { { 1,1,1,1,1,1 },
                        { 1,1,0,0,1,1 },
                        { 1,1,1,1,1,1 },
                        { 1,1,0,0,1,1 },
                        { 1,1,1,1,1,1 }  },

                      { { 1,1,1,1,1,1 },
                        { 1,1,0,0,1,1 },
                        { 1,1,1,1,1,1 },
                        { 0,0,0,0,1,1 },
                        { 0,0,0,0,1,1 }  }
                                            };

int Dots[5][4] ={       { 0,0,0,0 },
                        { 0,1,1,0 },
                        { 0,0,0,0 },
                        { 0,1,1,0 },
						{ 0,0,0,0 }  };


char buff[100];
	time_t now=time(0);

	strftime(buff,100,"%H:%M:%S", localtime(&now));

    strftime(buff,100,"%H", localtime(&now));
    int hour= atoi(buff);

    strftime(buff,100,"%M", localtime(&now));
    int Mins= atoi(buff);

    strftime(buff,100,"%S", localtime(&now));
    int Sec= atoi(buff);

int RequiredValues[8]={hour/10,hour%10,11,Mins/10,Mins%10,11,Sec/10,Sec%10};





//set new-console on;


printf("\n");
printf("\ec");
 printf("\e[?25l");
//printf("\e[?125");

foreclr=ChooseClr(clr);

printf("\n");
for(j=0;j<5;j++){



    for(l=0;l<8;l++){

            for(m=0;m<10;m++){
                if(RequiredValues[l]==m){

                printf(" ");
                for(k=0;k<6;k++){

                             if(Number[m][j][k] == 1){
                                    PrintFigureColor(foreclr);

                              }
                              else{
                                textcolor(BRIGHT,BLACK);
                                printf(" ");
                                textcolor(RESET,BLACK);
                                }
                            }
                           // printf(" ");

                    }


            }

         if((l==2)||(l==5)){
			textcolor(BRIGHT,BLACK);
			printf(" ");
			textcolor(RESET,BLACK);
             for(k=0;k<4;k++){

                             if(Dots[j][k] == 1){
                                    PrintFigureColor(foreclr);

                              }
                              else{
                                printf(" ");
                                }
                            }
                }


            }
            printf(" \n");

    }
}


void printAll(char *color){
while(1){
		printTime(color);

		printDate();
		sleep(1);

		printf("\ec");
	}
}
