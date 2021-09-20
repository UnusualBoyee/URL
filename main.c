// Aurthor : : Unusual Boyee
// Date    : : 2021/08/17
// Concept : : Url extraction from file.
// Main    : : voperatingsystem@gmail.com
// Country : : Nepal
/* This file is consider as main file to be compiled.
 * Program here is to checks arguments, keep content of given file_argument in buffer and to show details of time taken and urls printed/written. 
 * At final it calls function ESE to continue other operation. */

#include "logic"
#include "variable"
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void small_query(int argv);

char *_file;
int size;
char *main_file_buffer;

int main(int argv,char *argc[]){
	count_url=0;
	time_t t1,t2;
	t1=clock();
	_file=argc[1];	

	/*
	char cmd_buf[BUFSIZ];
	snprintf(cmd_buf,sizeof cmd_buf,"./preparation %s",_file);
	system(cmd_buf);
	*/

	small_query(argv);

	//_file_=".main_file";
	
/* Open up file to keep in buffer. */
	FILE *main_file=fopen(_file,"r");
	/* File may be null. 
	if( main_file==NULL){
		printf("-ERR- NULL\n");
		exit(1);
	} */
	fseek(main_file,0L,SEEK_END);
	size=ftell(main_file);
	rewind(main_file);
	main_file_buffer=malloc(size+1);
	fread(main_file_buffer,1,size,main_file);
	fclose(main_file);
/* Ending of buffering. */

/* Begining of function keept at logic header file. */
	ESE();
/* Ending */

	t2=clock();
	double top=(double)(t2-t1)/CLOCKS_PER_SEC;
	printf("\033[031m[\033[0m %f \033[031m]\033[0m TIME for \033[031m[\033[0m %d \033[031m]\033[0m URLs\n",top,count_url);

}
void small_query(int argv){
        if (argv!=2){
		printf("-ERR- ARGS\n");
		exit(1);
        }/*else if(argv>2){
                if ((strcmp(argc[1],"ERROR")==0) && (strcmp(argc[2],"LIST")==0)){
                help_modules();
                exit(1);
                }
        }*/else{
                if(access(_file,F_OK)!=0){
			printf("-ERR- :FNOT:\n");
                        exit(1);
                }
	}
}
